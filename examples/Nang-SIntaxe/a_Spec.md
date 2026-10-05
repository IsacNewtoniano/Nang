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












nomenclatures:
  [set] = literally a set, a pack...
  [symbol] = literally a symbol
  [def] = literally a definition
  [char] = any character
  [error] = determine the type of error
  [time] = time of Execution/Check/Solve
  [warning] = a specify Warning for the use

# Readability Rules
  Rules for clear code
# Lexical Rules
  Rules for lexical analysis
# Grammar Rules
  Rules for grammatical analysis
# Sintatic Rules
  Rules for Sintatic Rules analysis
# Semantic Rules
  Rules for Semantic Rules analysis

# Real Time
  Execution/Check/Solve in Real Time
# Comp Time
  Execution/Check/Solve in Compilation Time

# Memory
  Memory can increase or decrease.


# 0.0 UTF Decoder & Encoder

  # 0.0.0 UTF-8
    .Nang source files must be encoded in UTF-8

  # 0.0.1 UTF-16
    Internally supported

  # 0.0.2 UTF-32
    Internally supported


# 0.1 Default Sets

  # 0.1.0 a-z
    the set is {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}

  # 0.1.1 A-Z
    the set is {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z}

  # 0.1.2 0-9
    the set is {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

  # 0.1.3 Alphabet
  | [set](#010-a-z) AND/OR [set](#011-a-z)

  # 0.1.4 Commum
  | [set](#010-a-z)
  | AND/OR [set](#011-a-z) AND/OR
  | [set](#012-0-9)


# 1 Lexical

# 1.0.0.0 underline symbol
  the symbol is [_]

# 1.0.0.1 dot symbol
  the symbol is [.]

# 1.0.0.2 comma symbol
  the symbol is [,]



# 1.0.1.1 quot symbol
  the symbol is [']

# 1.0.1.2 double quot symbol
  the symbol is ["]



# 1.0.2 arithmetic symbols

  # 1.0.2.0 plus symbol
  | the symbol is [+]

  # 1.0.2.1 dash symbol
  | the symbol is [-]

  # 1.0.2.2 star symbol
  | the symbol is [*]

  # 1.0.2.3 slash symbol
  | the symbol is [/]

  # 1.0.2.4 modulo symbol
  | the symbol is [%]



# 1.0.3 Relational symbols

  # 1.0.3.0 open angle bracket
  | the symbol is [<]

  # 1.0.3.1 open angle bracket AND equals sign
  | the symbol is [<=]

  # 1.0.3.2 equals sign
  | the symbol is [=]
    def operator OR equal value operator

  # 1.0.3.3 double equals sign
  | the symbol is [==]
    equal type operator

  # 1.0.3.4 bang sign AND double equals sign
  | the symbol is [!==]
    different type operator

  # 1.0.3.5 bang sign AND equals sign
  | the symbol is [!=]
    different value operator

  # 1.0.3.6 close angle bracket
  | the symbol is [>]

  # 1.0.3.7 close angle bracket AND equals sign
  | the symbol is [>=]



# 1.0.4 Bitwase symbols

  # 1.0.4.0 triple open angle bracket 
  | the symbol is [<<<]
    *rotate left

  # 1.0.4.1 double open angle bracket AND pipe
  | the symbol is [<<|]
    *arithmetic shift left 

  # 1.0.4.2 double open angle bracket
  | the symbol is [<<]
    *shift left

  # 1.0.4.3 ampersand
  | the symbol is [&]
    *and

  # 1.0.4.4 pipe
  | the symbol is [|]
    *or

  # 1.0.4.5 caret
  | the symbol is [^]
    *xor

  # 1.0.4.6 tilde
  | the symbol is [~]
    *not

  # 1.0.4.7 double close angle bracket
  | the symbol is [>>]
    *shift right

  # 1.0.4.8 pipe AND double close angle bracket
  | the symbol is [|>>]
    *arithmetic shift right

  # 1.0.4.9 triple close angle bracket
  | the symbol is [>>>]
    *rotate right


# 1.0.5 Logical symbols

  # 1.0.5.0 double ampersand
  | the symbol is [&&]

  # 1.0.5.1 double pipe
  | the symbol is [||]

  # 1.0.5.2 double caret
  | the symbol is [^^]
    *logical xor

  # 1.0.5.3 bang sign
  | the symbol is [!]


# 1.1.0 binary digit set
  the set is {0, 1}

# 1.1.1 decimal digit set
  the set is {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

# 1.1.2 hexadecimal digit set
  the set is {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f}


# 1.1.3 binary numbers definition

  # 1.1.3.0 binary numbers definition
  | [set](#110-binary-digit-set) 
  → do it: 1001

  # 1.1.3.1 clear binary numbers definition
  | [set](#110-binary-digit-set)
  | AND [symbol](#1011-quot-symbol) AND
  | [set](#110-binary-digit-set)
  → do it: 1'0
  → don't: '1'0
  → don't: 1''0
  → don't: 1'0'
   → [error](#lexical-rules)
   → [time](#comp-time)
   → diagnostic: Do not use ['] at the ends, and do not use it doubled

# 1.1.4 decimal numbers definition

  # 1.1.4.0 decimal numbers definition
  | [set](#111-decimal-digit-set)
  → do it: 1903764825

  # 1.1.4.1 clear decimal numbers definition
  | [set](#111-decimal-digit-set)
  | AND [symbol](#1000-underline-symbol) AND
  | [set](#111-decimal-digit-set)
  → do it: 8_25
  → don't: _8_25
  → don't: 8__25
  → don't: 8_25_
   → [error](#lexical-rules)
   → [time](#comp-time)
   → diagnostic: Do not use [_] at the ends, and do not use it doubled

# 1.1.5 hexadecimal numbers definition

  # 1.1.5.0 hexadecimal numbers definition
  | [set](#112-hexadecimal-digit-set)
  → do it: 1d9a03c76be482f5

  # 1.1.5.1 clear hexadecimal numbers definition
  | [set](#112-hexadecimal-digit-set)
  | AND [symbol](#1012-double-quot-symbol) AND
  | [set](#112-hexadecimal-digit-set)
  → do it: 4a"f
  → don't: "4a"f
  → don't: 4a""f
  → don't: 4a"f"
   → [error](#lexical-rules)
   → [time](#comp-time)

   → diagnostic: Do not use ["] at the ends, and do not use it doubled


# 1.1.6 Integers Number definition

  # 1.1.6.0 Integers Form
  | [def](#113-binary-numbers-definition)
  | OR [def](#114-decimal-numbers-definition) OR
  | [def](#115-hexadecimal-numbers-definition)

  # 1.1.6.1 Positive Integers
  | [def](#1160-integers-form)

  # 1.1.6.2 Negative Integers
  | [symbol](#1021-dash-symbol) AND [def](#1160-integers-form)
   → [time](#comp-time)

# 1.1.7 Decimal Number definition
  It is a floating-point number;
  [.] is not a member access operator.

  # 1.1.7.0 Decimal Form
  | [def](#1140-decimal-numbers-definition)
  | AND [symbol](#1001-dot-symbol) AND
  | [def](#1140-decimal-numbers-definition)

  # 1.1.7.1 Positive Decimal
  | [def](#1170-decimal-form)

  # 1.1.7.2 Negative Decimal
  | [symbol](#1021-dash-symbol) AND [def](#1170-decimal-form)
   → [time](#comp-time)
  

# 1.2.0 String definition

  # 1.2.0.0 Single-Line string form
  | [symbol](#1011-quot-symbol)
  | AND [set](#100-utf-8) AND
  | [symbol](#1011-quot-symbol)
  → do it: 'string example 0123456789 [{()}]'
  → don't: 'string example
                0123456789 [{()}]'
   → [error](#readability-rules)
   → [time](#comp-time)
   → diagnostic: ['] do not support multiple lines

  # 1.2.0.1 Multi-Line string form
  | [symbol](#1012-double-quot-symbol)
  | AND [set](#000-utf-8) AND
  | [symbol](#1012-double-quot-symbol)
  → do it: "string example
            0123456789 [{()}]"
  → don't: "string example 0123456789 [{()}]"
   → [error](#readability-rules)
   → [time](#comp-time)
   → diagnostic: ["] do not support single line

  # 1.2.0.2 String form
  | [def](#1200-single-line-string-form)
  | OR [def](#1201-multi-line-string-form)

# 1.2.1 String Prefix

  # 1.2.1.0 Formated String
  | [char](f) OR [char](F)
  | AND [def](#1202-string-form)

  # 1.2.1.1 Wide String
  UTF-8 is converted to UTF-16 [set](#001-utf-16)
  | [char](w) OR [char](W)
  | AND [def](#1202-string-form)

  # 1.2.1.2 Double-Wide String
  UTF-8 [set](#000-utf-8) is converted to UTF-32 [set](#002-utf-32)
  | [char](dw) OR [char](DW)
  | AND [def](#1202-string-form)

  # 1.2.1.3 String Prefix Error
   → [error](#sintatic-rules)
   → [time](#comp-time)
   → diagnostic: String ["]/['] Prefix do not support others Prefix, only [f]/[F], [w]/[W], [dw]/[DW]
  # 1.2.1.4 String Prefix Error
   → [error](#sintatic-rules)
   → [time](#comp-time)
   → diagnostic: String ["]/['] Prefix do not support Space [ ]


# 1.2.2 String Sufix
  A suffix is a String metadata

  # 1.2.2.0 String Sufix definition
  | [def](#1202-string-form) AND [set](#013-alphabet)
  → do it: "a literally CompileR"formated
  → don't: "a literally CompileR" formated
   → [error](#sintatic-rules)
   → [time](#comp-time)
   → diagnostic: String ["]/['] Sufix do not support Space [ ]


# 1.3 Special Keys

  # 1.3.0 Commun Keys
    the set is {imut, mut,}

  # 1.3.1 Type Keys
    the set is {i8, u8, i16, u16, f16, i32, u32, f32, i64, u64, f64, i128, u128, f128, bool, gnpointer,
                import, pointer}

  # 1.3.2 Special Keys set
  | the set is [set](#130-commun-keys) AND [set](#131-type-keys)


# 1.4 Identifier

  # 1.4.0 Init Identifier
  | [symbol](#1000-underline-symbol) OR [set](#013-alphabet)

  # 1.4.1.0 Identifier definition
  | [def](#140-init-identifier)

  # 1.4.1.1 Identifier definition
  | [def](#140-init-identifier) AND [set](#013-alphabet) OR [symbol](#1000-underline-symbol)

  # 1.4.2 Identifier Error
  → [def](#14-identifier) Is Not [def](#132-special-keys-set)
   → [error](#sintatic-rules)
   → [time](#comp-time)