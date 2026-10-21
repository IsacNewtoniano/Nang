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

#include "Types.h"
#include <stdio.h>


//* Cycles to ns
#define ct_ns(_uint64) ((f64)(_uint64) * Global_Frequency.ns)
//* Cycles to us
#define ct_us(_uint64) ((f64)(_uint64) * Global_Frequency.us)
//* Cycles to ms
#define ct_ms(_uint64) ((f64)(_uint64) * Global_Frequency.ms)
//* Cycles to s
#define ct_s(_uint64) ((f64)(_uint64) * Global_Frequency.s)

/*
Ryzen 3 2200G
Total Loop Time: 1886.3054896971
Loop Op Time: Sum Val: 3169430160294
  Average ns Time: 25.154207621
  Min cs Time: 70
  Min ns Time: 20.000000000
  Max ns Time: 483724607.428571403

cs = Cycles
*/
#define Precise_Time(Cycles_Time) ((Cycles_Time) >= 70 ? Cycles_Time - 70 : 0)

#include <windows.h>

typedef struct{
  f64 ns; //* Pre-Compute
  f64 us; //* Pre-Compute
  f64 ms; //* Pre-Compute
  f64 s; //* Pre-Compute
  LONGLONG freq;
} TimePreCompute;

static TimePreCompute Global_Frequency = {
  0,0,0,0,0
};


static inline u64 init_time() {
    u64 result;
    __asm__ __volatile__ (
        "lfence\n\t"
        "rdtsc\n\t"
        "shl $32, %%rdx\n\t"
        "or %%rdx, %%rax\n\t"
        "lfence"
        : "=a" (result)
        :
        : "rdx"
    );
    return result;
}

static inline u64 end_time() {
    u64 result;
    __asm__ __volatile__ (
        "rdtscp\n\t"
        "shl $32, %%rdx\n\t"
        "or %%rdx, %%rax\n\t"
        "lfence"
        : "=a" (result)
        :
        : "rdx", "rcx"
    );
    return result;
}

void Initialize_Timer(u64 Frequency) {
  if (!Frequency){
    LARGE_INTEGER qpc_freq, qpc_start, qpc_end;
    
    QueryPerformanceFrequency(&qpc_freq);
    
    timeBeginPeriod(1);
    
    QueryPerformanceCounter(&qpc_start);
    u64 tsc_start = init_time();
    
    Sleep(100);  //? 100ms
    
    QueryPerformanceCounter(&qpc_end);
    u64 tsc_end = end_time();
    
    timeEndPeriod(1);
    
    //? Real TSC Frequency
    double qpc_elapsed = (double)(qpc_end.QuadPart - qpc_start.QuadPart) / qpc_freq.QuadPart;
    Global_Frequency.freq = (i64)((tsc_end - tsc_start) / qpc_elapsed);
  } else {
    Global_Frequency.freq = Frequency;
  }
  
  Global_Frequency.s  = 1.0 / Global_Frequency.freq;
  Global_Frequency.ms = 1000.0 / Global_Frequency.freq;
  Global_Frequency.us = 1000000.0 / Global_Frequency.freq;
  Global_Frequency.ns = 1000000000.0 / Global_Frequency.freq;
}