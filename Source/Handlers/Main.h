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
#include "Structs.h"

typedef __attribute__((aligned(8))) struct {
  /*
  * Optimization flags Level for the compiler.
  * 0 = No         optimization AND Flash Compile
  * 1 = Basic      optimization AND Flash Compile
  * 2 = Aggressive optimization AND Slow  Compile
  * 3 = Maximum    optimization AND Slow  Compile
  */

  // !Optimization flags Level for the compiler.
  unsigned Opt0: 1;
  unsigned Opt1: 1;
  unsigned Opt2: 1;
  unsigned Opt3: 1;

  /*
  * Reporting flags for the compiler.
  * TerminalReport = Make Report File WITH all reports, warnings, errors, and suggestions.
  * Report = Make Report File WITH all reports, warnings, errors, and suggestions.
  * Warning = Make Report File WITH all warnings.
  * Error = Make Report File WITH all errors.
  * Suggestion = Make Report File WITH all suggestions.

  * NonReport = Ignore All reports, warnings, errors, and suggestions.
  * NonWarning = Ignore All warnings.
  * NonError = Ignore All errors.
    * NonSuggestion = Ignore All suggestions.
  */

  // !Reporting flags for the compiler.
  unsigned TerminalReport: 1;
  unsigned Report: 1;
  unsigned Warning: 1;
  unsigned Error: 1;
  unsigned Suggestion: 1;
  unsigned NonReport: 1;
  unsigned NonWarning: 1;
  unsigned NonError: 1;
  unsigned NonSuggestion: 1;
} CompilerFlags;

typedef __attribute__((aligned(8))) struct {

} BuildStruct;

typedef __attribute__((aligned(8))) struct {
  wchar_t *Nang_Directory;
  wchar_t *BuildFile_Directory;
  wchar_t *File_to_Compile_Directory;
  void *Source_File_Path_Addres; //! File for Compiler Process
  void *LPS_Struct;
} CompilerStruct;