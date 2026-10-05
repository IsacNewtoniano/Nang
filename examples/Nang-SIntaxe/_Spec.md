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












# How to Read This Specification
 ## Document Notation
    []:
      Square brackets are used to define the type of rule that will be referenced.
    
    (x.x.x.x.x):
      Parentheses are used to indicate the reference.

    Example:
      [symbol](1.100.50.0.20)

    x.x.x.x.x:
      Identifiers must be a:

       First component:
        A part of the compilation.

       Second component:
        Specific rules or broad rules.
         By default, it uses values ​​in increments of 100, but intermediate values ​​are possible.

       Third component:
        First Subdivision: Similar rules.
         By default, it uses values ​​in increments of 50, but intermediate values ​​are possible.

       Fourth component:
        Second Subdivision: Slightly different rules.
         By default, it uses values ​​in increments of 25, but intermediate values ​​are possible.

       Fifth component:
        Third Subdivision: Last Subdivision.
         By default, it uses values ​​in increments of 10, but intermediate values ​​are possible.

      Examples:
        # 0.300.150.75.30
        # 4.1200.0.0.90
        with intermediate:
          # 3.35.22.10.5
          # 2.15.49.33.58

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
       |      └────└─ Firt
       └───────────── Second
      IS
      Choose 0 or 1.

      First case: _0
      Last  case: _1

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

  ## To conclude
    For correct and proper reading, this does not interfere with the language's syntax or the compiler's actions.