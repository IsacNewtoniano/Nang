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
#include "Librarys/Terminal.c"

#include "Handlers/Types.h"
#include "Handlers/Utils.h"

#include "Handlers/Main.h"
#include "Handlers/Structs.h"

#include <stdio.h>
#include <windows.h>

#define Nang_Directory_Buffer_Size 256

int main(int ArgC, char **ArgV) {
  system("cls");
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  Arena *Alloc = Init_Arena(KB(32), KB(8));
  
  wchar_t *Nang_Directory = (wchar_t *)Arena_Alloc(Alloc, Nang_Directory_Buffer_Size);

  DWORD Size = GetCurrentDirectoryW(
    Nang_Directory_Buffer_Size,
    Nang_Directory
  );

  if (Size == 0) {
    printf("Error getting current directory: %lu\n", GetLastError());
    return 1;
  }
  
  for (u8 i = 0; i <= Size; i++){
    putwchar(Nang_Directory[i]);
  }

  progress(50, 20);

  if (ArgC < 2){
    printf("");
  }
  printf("\n\n");
  for (int I = 0; I < ArgC; I++) {
    printf("ArgV[%u] = %s\n", I, ArgV[I]);
  }

  return 0;
}

// Current Compile C args: clang -O3 -o Nang.exe Source/Nang.c
// Current Compile Nang args: ./nang .build