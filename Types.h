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

typedef signed char i8;
typedef unsigned char u8;

typedef signed short i16;
typedef unsigned short u16;

typedef signed int i32;
typedef unsigned int u32;
typedef float f32;

typedef signed long long int i64;
typedef unsigned long long int u64;
typedef double f64;

typedef u8 *byte_pt;
typedef void *generic_pt;
typedef void non_return;

typedef enum : signed char{
  upper = 1,
  standard = 0,
  lower = -1,
} ternary;

typedef enum : signed char{
  successful = 1,
  none = 0,
  failed = -1
} err;

#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)
#define TiB(n) ((u64)(n) << 40)

#define Windows_PageSize ((u64)4096)
#define Mask_PageSize ((u64)4095)
#define Mask_Inverse_PageSize ((u64)0xfffffffffffff000)
#define Windows_MemoryLimit 281474976710656