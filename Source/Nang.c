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












#include "Librarys/Mem.c"

#include "Handlers/Types.h"
#include "Handlers/Utils.h"

#include <stdio.h>
#include <windows.h>

int main(int ArgC, char **ArgV) {
  Arena *Alloc = Init_Arena(KB(32), KB(8));
  
  wchar_t Buffer[256];

  DWORD Size = GetCurrentDirectoryW(
    256,
    Buffer
  );

  if (Size == 0) {
    printf("Error getting current directory: %lu\n", GetLastError());
    return 1;
  }
  
  for (u8 i = 0; i <= Size; i++){
    putwchar(Buffer[i]);
  }
  char *SourcePath = NULL;

  
  printf("\n");
  for (int I = 0; I < ArgC; I++) {
    printf("ArgV[%u] = %s\n", I, ArgV[I]);
  }

  return 0;
}

// Current Compile C args: clang -O3 -o Nang.exe Nang.c
// Current Compile Nang args: ./build: nang .build