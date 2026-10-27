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










#include "Types.h"

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

typedef enum: u8 {
  If_Key,
  Else_Key,
  Match_Key,
  Case_Key,
  Coringa_Key,
  Function_Key,
  Class_Key,
  Struct_Key,
  Record_Key,
  Break_Key,
  Continue_Key,
  Return_Key,
  Defer_Key,
  Inline_Key,
  FuncSpec_Key,
  Variable_Key,
} Special_Key;

typedef enum: u8 {
  Imut_Type,
  mut_Type,
  ReadOnly_Type,
  Private_Type,
  Public_Type,
} VisibilityType;

typedef enum: u8 {
  U8_Type,
  U16_Type,
  U32_Type,
  U64_Type,
  U128_Type,
  U256_Type,

  I8_Type,
  I16_Type,
  I32_Type,
  I64_Type,
  I128_Type,
  I256_Type,

  F16_Type,
  F32_Type,
  F64_Type,
  F128_Type,

  ClassPointer_Type,
  StructPointer_Type,
  RecordPointer_Type,
  GenericPointer_Type,
  FunctionPointer_Type,

} Type;

typedef enum: u8 {
  Add_Type, //* +
  Sub_Type, //* -
  Mul_Type, //* *
  Div_Type, //* /
  Mod_Type, //* %

  Binary_And_Type, //* &
  Binary_Or_Type,  //* |
  Binary_Xor_Type, //* ^
  Binary_Not_Type, //* ~

  And_Type, //* && and
  Or_Type,  //* || or
  Xor_Type, //* ^^ not
  Not_Type, //* ! not

  LeftShift_Type,             //* <<
  RightShift_Type,            //* >>
  Arithmetic_RightShift_Type, //* |>
  Arithmetic_LeftShift_Type,  //* <|
  LeftRotate_Type,            //* <<<
  RightRotate_Type,           //* >>>
  
  Equal_Type,        //* =
  NotEqual_Type,     //* !=
  Greater_Type,      //* >
  GreaterEqual_Type, //* >=
  Less_Type,         //* <
  LessEqual_Type,    //* <=
  
  EqualType_Type,     //* ==
  NotEqualType_Type,  //* !==

  Parenthesis_Type, //* ()
  Bracket_Type,     //* []
  Block_Type,       //* {}
  Dot_Type,         //* .

  Function_Type, //* function call
  Variable_Type, //* variable value
} Expression_Type;

typedef enum: u8 {
  Function_Precedence     = 0,
  Variable_Precedence     = 0,
  Value_Precedence     = 0,

  Dot_Precedence         = 1,
  Bracket_Precedence     = 1,

  Parenthesis_Precedence = 2,

  Add_Precedence    = 3,
  Sub_Precedence    = 3,

  Mul_Precedence    = 4,
  IntDiv_Precedence = 4,
  Div_Precedence    = 4,

  Mod_Precedence    = 5,

  Binary_And_Precedence = 6,
  Binary_Or_Precedence  = 6,
  Binary_Xor_Precedence = 6,
  Binary_Not_Precedence = 6,

  Not_Precedence = 7,
  And_Precedence = 8,
  Or_Precedence  = 9,
  Xor_Precedence = 9,

  LeftShift_Precedence             = 10,
  RightShift_Precedence            = 10,
  Arithmetic_RightShift_Precedence = 10,
  Arithmetic_LeftShift_Precedence  = 10,
  LeftRotate_Precedence            = 10,
  RightRotate_Precedence           = 10,

  Equal_Precedence        = 11,
  NotEqual_Precedence     = 11,
  Greater_Precedence      = 11,
  GreaterEqual_Precedence = 11,
  Less_Precedence         = 11,
  LessEqual_Precedence    = 11,

  EqualType_Precedence     = 12,
  NotEqualType_Precedence  = 12,

  Block_Precedence       = 13,

} Expression_Precedence;