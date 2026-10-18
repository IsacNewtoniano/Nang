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












# How To Read This Specification
 ## Document Notation
    []:
      Square brackets are used to define the type of rule to be referenced or the character from a set.

    (x.x.x.x):
      Parentheses are used to indicate the reference.

    Example:
      [symbol](100.50.0.20)

    (Rules):
      Parentheses are used to indicate the precedence.

    Example:
      (A AND B) OR C
            └──────────────────────┴─ Firt           |
                                                     └────── Second
      IS
      Choose A and B or C.

      First case: A AND B
      Last  case: C


    *:
      one or more
    
    Example:
      [A](0.0.75.40)*
      IS
      A, AA, AAA, AAAA, AAAAA...

    x.x.x.x.x:
      Identifiers must be a:
       Second component:
        Specific rules or broad rules.
         By default, it uses values ​​in increments of 100, but intermediate values ​​are possible.

       Second component:
        First Subdivision: Similar rules.
         By default, it uses values ​​in increments of 50, but intermediate values ​​are possible.

       Third component:
        Second Subdivision: Slightly different rules.
         By default, it uses values ​​in increments of 25, but intermediate values ​​are possible.

       Fourth component:
        Third Subdivision: Last Subdivision.
         By default, it uses values ​​in increments of 10, but intermediate values ​​are possible.

      Examples:
        # 300.150.75.30
        # 1200.0.0.90
        with intermediate:
          # 35.22.10.5
          # 15.49.33.58

 ## 'AND'/'OR' & Precedence
    AND:
      It can be a concatenation of syntax or a combination of rules.
    OR:
      It's a choice between two.

    Precedence:
      OR -> First
      AND -> Second

    Example:
      '_' AND 0 OR 1
       └──────┴────┼── Firt
                   └────── Second
      IS
      Choose ('_' and 0) or 1.

      First case: _0
      Last  case: 1

 ## Normative Language
    MUST:
      This word, or the terms "REQUIRED", mean that the
      definition is an absolute requirement of the specification.

    MUST NOT:
      This phrase, mean that the definition is an absolute
      prohibition of the specification.

    SHOULD:
      This word, or the adjective "RECOMMENDED", mean that there
      may exist valid reasons in particular circumstances to ignore a
      particular item, but the full implications must be understood and
      carefully weighed before choosing a different course.

    SHOULD NOT:
      This phrase, or the phrase "NOT RECOMMENDED" mean that
      there may exist valid reasons in particular circumstances when the
      particular behavior is acceptable or even useful, but the full
      implications should be understood and the case carefully weighed
      before implementing any behavior described with this label.

  ## To Conclude
    For correct and proper reading, this does not interfere with the language's syntax or the compiler's actions.

# Source File Format
  .Nang source files must be encoded in UTF-8

  MUST: UTF-8 encoding
  MUST NOT: BOM(Byte Order Mark)

  UTF-16 and UTF-32 are used internally only for conversions from UTF-8.

# Accepted Character Set
  The set is {`a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
              A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z`}

  For more than one, use this format:
    a-z = a, b, c, d, e, f, g, ..., z
    A-Z = A, B, C, D, E, F, G, ..., Z
    a-Z = a, b, c, d, e, f, g, ..., T, U, V, W, X, Y, Z
    d-i = d, e, f, g, h, i


# Accepted Digit Set
  The set is {`0, 1, 2, 3, 4, 5, 6, 7, 8, 9`}

  For more than one, use this format:
    0-9 = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    1-9 = 1, 2 ..., 9
    4-7 = 4, 6, 7

# Accepted Symbol Set
  The set is {
    ` `
    `_`
    `.`
    `,`
    `'`
    `"`
    `+`
    `-`
    `*`
    `/`
    `%`
    `<`
    `=`
    `>`
    `|`
    `!`
    `&`
    `^`
    `~`
    `\`
    `@`
    `#`
    `;`
    `:`
    `?`
    `[`
    `]`
    `{`
    `}`
    `(`
    `)`
  }

# All Accepet UTF-8 Character
  [set] AND [set] AND [set] AND the set in decimal code {
    10,
    32
  }

  ## binary number digit set
    the set is {0, 1}
    For all, use this format:
      0-1 = 0, 1

  ## Decimal number digit set
    the set is {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    For more than one, use this format:
      0-9 = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
      1-9 = 1, 2, ..., 9
      4-7 = 4, 6, 7

  ## Hexadecimal number digit set
    the set is {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                a/A, b/B, c/C, d/D, e/E, f/F}
    For more than one, use this format:
      0-f = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, B, C, d, e, F
      1-F = 1, 2, ..., F
      7-b = 7, 8, ..., b


# 0.0.0.0
  Binary Number

  MUST: Use the set [Set](#binary-number-digit-set)

  Define the accepted syntax for binary number initialization: v0
    [0] AND [b/B]
    MUST:
      0b
      0B
    MUST NOT:
      b0
      B0
      Diagnostic:
        This can be mistaken for an identifier, which can lead to identifier-related errors.
        [errors](número dos erros de identificador)
    MUST: [0:Set](#accepted-digit-set) and [b, B:Set](#accepted-character-set)

  Define the accepted syntax for the post-initialization of binary numbers: v0
    [0]
    MUST:
      0
    MUST NOT:
      0...1
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST: [0-1:Set](#binary-number-digit-set)

  Define the accepted syntax for the post-initialization of binary numbers: v1
    [1]* OR ([1]* AND [0-1]*)
    MUST:
      1
      101
      11011
    MUST NOT:
      0...10
      0...101
      0...11011
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST: [0, 1:Set](#binary-number-digit-set)

  Define the accepted syntax for the post-initialization of binary numbers: v2
    [1]* AND ([0-1] OR [_])* AND [0-1]*
    MUST:
      1_01
      11_0_11
    MUST NOT:
      0...1_01
      0...11_0_11
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST NOT:
      1_01_
      11_0_11_
      Diagnostic:
        The symbol [_] indicates a continuation and must not conclude a number.
    MUST NOT:
      1__01
      11__0___11
      Diagnostic:
        Use the [_] only once per separator
    MUST NOT:
      _101
      _11011
      Diagnostic:
        The symbol [_] must not be used at the beginning.
    MUST: [0, 1:Set](#binary-number-digit-set) and [_:Set](#accepted-symbol-set)

  Defines the maximum number of digits accepted for binary numbers (after initialization):
    The maximum is: 65536
    Underscore doesn't count

  Complete Syntax of binary numbers:
    MUST:
      0B0
      0B1
      0b010101
      0b01_01_01
    MUST NOT:
      0B 0
      0B  1
      0b 010101
      0b  01_01_01
      0B  01_ 01 _01
      Diagnostic:
        The space [ ](#accepted-symbol-set) is invalid, and the compiler does not expect it.


# 0.0.0.10
  Decimal Number

  MUST: Use the set [Set](#decimal-number-digit-set)

  Define the accepted syntax for decimal numbers: v0
    [0]
    MUST:
      0
    MUST NOT:
      0...1-9
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST: [0-9:Set](#decimal-number-digit-set)

  Define the accepted syntax for decimal numbers: v1
    [1-9]* OR ( [1-9]* AND [0-9]* )
    MUST:
      1
      32
      4096
    MUST NOT:
      0...1
      0...32
      0...4096
      0...1-9
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST: [0-9:Set](#decimal-number-digit-set)

  Define the accepted syntax for decimal numbers: v2
    [1-9]* AND ([0-9] OR [_])* AND [0-9]*
    MUST:
      3_2
      4_096
    MUST NOT:
      0...4_096
      0...3_2
      0...1-9_1-9
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST NOT:
      3_2_
      4_096_
      Diagnostic:
        The symbol [_] indicates a continuation and must not conclude a number.
    MUST NOT:
      32__64
      4__096___128
      Diagnostic:
        Use the [_] only once per separator
    MUST NOT:
      _32
      _4096
      Diagnostic:
        The symbol [_] must not be used at the beginning.
    MUST: [0-9:Set](#decimal-number-digit-set) and [_:Set](#accepted-symbol-set)

  Defines the maximum number of digits accepted for decimal numbers (after initialization):
    The maximum is:  19729
    Underscore doesn't count

  Complete Syntax of decimal numbers:
    MUST:
      0
      256
      128
    MUST NOT:
      2 56
      40 96
      3 2
      Diagnostic:
        The space [ ](#accepted-symbol-set) is invalid, and the compiler does not expect it.
    MUST NOT:
      0b
      0B
      Diagnotic:
        Initialization merely initializes the number; do not use it in isolation.

# 0.0.0.20
  Hexadecimal Number

  MUST: Use the set [Set](#hexadecimal-number-digit-set)

  Define the accepted syntax for hexadecimal number initialization: v0
    [0] AND [x/X]
    MUST:
      0x
      0X
    MUST NOT:
      x0
      X0
      Diagnostic:
        This can be mistaken for an identifier, which can lead to identifier-related errors.
        [errors](número dos erros de identificador)
    MUST: [0:Set](#accepted-digit-set) and [x, X:Set](#accepted-character-set)

  Define the accepted syntax for the post-initialization of hexadecimal numbers: v0
    [0]
    MUST:
      0
    MUST NOT:
      0...1-f
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST: [0-f:Set](#hexadecimal-number-digit-set)

  Define the accepted syntax for the post-initialization of hexadecimal numbers: v1
    [1-f]* OR ([1-f]* AND [0-f]*)
    MUST:
      1b2c
      f0f0
      9f8b10
    MUST NOT:
      0...1b2c
      0...f0f0
      0...9f8b10
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST: [0-f:Set](#hexadecimal-number-digit-set)

  Define the accepted syntax for the post-initialization of hexadecimal numbers: v2
    [1-f]* AND ([0-f] OR [_])* AND [0-f]*
    MUST:
      1b_2c
      f0_f0
      9f_8b_10
    MUST NOT:
      0...1b_2c
      0...f0_f0
      0...9f_8b_10
      Diagnostic:
        A leading zero [0] does not affect the result, so do not include it.
    MUST NOT:
      1b_2c_
      9f_8b_10_
      Diagnostic:
        The symbol [_] indicates a continuation and must not conclude a number.
    MUST NOT:
      1b__2c
      9f__8b___10
      Diagnostic:
        Use the [_] only once per separator
    MUST NOT:
      _1b2c
      _9f8b10
      Diagnostic:
        The symbol [_] must not be used at the beginning.
    MUST: [0-f:Set](#hexadecimal-number-digit-set) and [_:Set](#accepted-symbol-set)

  Defines the maximum number of digits accepted for hexadecimal numbers (after initialization):
    The maximum is: 16384
    Underscore doesn't count

  Complete Syntax of hexadecimal numbers:
    MUST:
      0X0
      0X1b2c
      0x9f8b10
      0x9f_8b_10
    MUST NOT:
      0X 0
      0X  1
      0x 9f8b10
      0x  9f_8b_10
      0X  9f_ 8b _10
      Diagnostic:
        The space [ ](#accepted-symbol-set) is invalid, and the compiler does not expect it.
    MUST NOT:
      0x
      0X
      Diagnotic:
        Initialization merely initializes the number; do not use it in isolation.