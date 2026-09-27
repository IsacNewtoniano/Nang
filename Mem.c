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










#pragma once

#include <windows.h>

#include "Types.h"
#include "Utils.h"

typedef __attribute__((aligned(8))) struct {
  byte_pt End;
  byte_pt Offset;

  byte_pt Committed;
  u64     EAlloc_Size;
} Arena;

_Static_assert(sizeof(Arena) == 32, "AAllocS USE JUST 32 BYTES");

Arena *Init_Arena(u64 Bytes, i64 Extra_Alloc);

generic_pt Arena_Alloc(Arena *Alloc, u64 Size);
inline generic_pt Unsafe_Arena_Alloc(Arena *Alloc, u64 Size);
generic_pt Align_Arena_Alloc(Arena *Alloc, u64 Size, u64 Align);

inline non_return Arena_Offset(Arena *Alloc, u64 Offset);
inline non_return Arena_End(Arena **Alloc);

Arena *Init_Arena(u64 Bytes, i64 Extra_Alloc) {
  u64 Round_Size        = (Bytes + 32 + Mask_PageSize) & Mask_Inverse_PageSize;
  u64 Round_Extra_Alloc = (Extra_Alloc + Mask_PageSize) & Mask_Inverse_PageSize;

  generic_pt base = VirtualAlloc (
    NULL, 
    Round_Size, 
    MEM_RESERVE, 
    PAGE_READWRITE);

  if (!base) {
    return NULL;
  }

  u64 Commit_Size = Windows_PageSize;

  if (Round_Size >= Round_Extra_Alloc << 1)
    Commit_Size = Round_Extra_Alloc;

  generic_pt commit_base = VirtualAlloc (
    (generic_pt)base,
    Commit_Size,
    MEM_COMMIT,
    PAGE_READWRITE
  );

  if (!commit_base) {
    VirtualFree (
      base,
      0,
      MEM_RELEASE
    );
    return NULL;
  }

  Arena *Alloc = (Arena *)base;

  Alloc->Offset    =
    (byte_pt)Alloc + sizeof(Arena);

  Alloc->Committed =
    (byte_pt)Alloc + Commit_Size;

  Alloc->EAlloc_Size = Round_Extra_Alloc;
  Alloc->End         = (byte_pt)base + Round_Size;

  return Alloc;
}

generic_pt Arena_Alloc(Arena *Alloc, u64 Size) {
  byte_pt Committed = Alloc->Committed;
  byte_pt Offset    = Alloc->Offset;

  u64 Available      = (u64) (Committed - Offset);
  byte_pt Ptr_Offset = Offset;

  if (Size <= Available) {
    Alloc->Offset += Size;
    return  (generic_pt) Ptr_Offset;
  }

  byte_pt End = Alloc->End;

  u64 Remaining      = (u64)Size - (u64)Available;
  u64 Alloc_Size     = (Remaining + Mask_PageSize) & Mask_Inverse_PageSize;

  u64 Extra_Size  = Alloc->EAlloc_Size;
  u64 Commit_Size = Extra_Size;

  u64 Size_Interval = (u64) (End-Ptr_Offset);

  if (Alloc_Size > Size_Interval)
    return NULL;

  if (Commit_Size > Size_Interval || Commit_Size < Alloc_Size)
    Commit_Size = Alloc_Size;

  generic_pt base = VirtualAlloc (
    (generic_pt) Committed,
    Commit_Size,
    MEM_COMMIT,
    PAGE_READWRITE);

  if (!base) {
    return NULL;
  }

  Alloc->Committed += Commit_Size;
  Alloc->Offset    += Size;

  generic_pt Ptr = (generic_pt) Ptr_Offset;
  return Ptr;
}

inline generic_pt Unsafe_Arena_Alloc(Arena *Alloc, u64 Size) {
  byte_pt Offset = Alloc->Offset;

  Alloc->Offset = Offset + Size;
  return (generic_pt)Offset;
}

generic_pt Align_Arena_Alloc(Arena *Alloc, u64 Size, u64 Align) {
  if (popcount(Align) != 1)
    return NULL;

  byte_pt Committed = Alloc->Committed;
  u64 Mask = Align - 1;
  byte_pt Offset    = (byte_pt) (
    ((u64)Alloc->Offset + (Mask)) & ~Mask
  );

  u64 Available      = (u64) (Committed - Offset);
  byte_pt Ptr_Offset = Offset;

  if (Size <= Available) {
    Alloc->Offset += Size;
    return  (generic_pt) Ptr_Offset;
  }

  byte_pt End = Alloc->End;

  u64 Remaining      = abs((i64)Size - (i64)Available);
  u64 Alloc_Size     = (Remaining + Mask_PageSize) & Mask_Inverse_PageSize;

  u64 Extra_Size  = Alloc->EAlloc_Size;
  u64 Commit_Size = Extra_Size;

  u64 Size_Interval = (u64) (End-Ptr_Offset);

  if (Alloc_Size > Size_Interval)
    return NULL;

  if (Commit_Size > Size_Interval || Commit_Size < Alloc_Size)
    Commit_Size = Alloc_Size;

  generic_pt base = VirtualAlloc (
    (generic_pt) Committed,
    Commit_Size,
    MEM_COMMIT,
    PAGE_READWRITE);

  if (!base) {
    return NULL;
  }

  Alloc->Committed += Commit_Size;
  Alloc->Offset    += Size;

  generic_pt Ptr = (generic_pt) Ptr_Offset;
  return Ptr;
}

inline non_return Arena_Offset(Arena *Alloc, u64 Offset) {
  Alloc->Offset = (byte_pt)Alloc + sizeof(Arena) + Offset;
}

inline non_return Arena_End(Arena **Alloc) {
  VirtualFree(
    *Alloc,
    0,
    MEM_RELEASE
  );

  *Alloc = NULL;
}
