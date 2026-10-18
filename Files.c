/*
  Copyright 2026 Isac Jônatas de Oliveira

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/










#include <windows.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
  HANDLE File;
  HANDLE Mapping;
  const void *Data;
  uint64_t Size;
} FileView;

bool File_OpenRead(
  const wchar_t *Path,
  FileView *Out
) {
  Out->File = INVALID_HANDLE_VALUE;
  Out->Mapping = NULL;
  Out->Data = NULL;
  Out->Size = 0;

  HANDLE File = CreateFileW(
    Path,
    GENERIC_READ,
    FILE_SHARE_READ,
    NULL,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    NULL
  );

  if (File == INVALID_HANDLE_VALUE) {
    return false;
  }

  LARGE_INTEGER FileSize;

  if (!GetFileSizeEx(File, &FileSize)) {
    CloseHandle(File);
    return false;
  }

  if (FileSize.QuadPart <= 0) {
    CloseHandle(File);
    return false;
  }

  HANDLE Mapping = CreateFileMappingW(
    File,
    NULL,
    PAGE_READONLY,
    0,
    0,
    NULL
  );

  if (Mapping == NULL) {
    CloseHandle(File);
    return false;
  }

  const void *Data = MapViewOfFile(
    Mapping,
    FILE_MAP_READ,
    0,
    0,
    0
  );

  if (Data == NULL) {
    CloseHandle(Mapping);
    CloseHandle(File);
    return false;
  }

  Out->File = File;
  Out->Mapping = Mapping;
  Out->Data = Data;
  Out->Size = (uint64_t)FileSize.QuadPart;

  return true;
}

void File_Close(FileView *View) {
  if (View->Data != NULL) {
    UnmapViewOfFile(View->Data);
  }

  if (View->Mapping != NULL) {
    CloseHandle(View->Mapping);
  }

  if (View->File != INVALID_HANDLE_VALUE) {
    CloseHandle(View->File);
  }

  View->Data = NULL;
  View->Mapping = NULL;
  View->File = INVALID_HANDLE_VALUE;
  View->Size = 0;
}