# stack


In infix, the operator goes between its operands: A+B. In prefix, it goes before its operands: +AB. In postfix, it goes after them: AB+.


## infix to prefix

eg: A-B-C*(D+E)

Step 1: reverese the string and swap the parenthesis (E+D)*C-B-A

| Step | Read | Action | Operator stack (bottom to top) | Temporary output |
|---:|:---:|---|---|---|
| 1 | `(` | Push the opening parenthesis | `(` | |
| 2 | `E` | Copy operand | `(` | `E` |
| 3 | `+` | Push operator | `( +` | `E` |
| 4 | `D` | Copy operand | `( +` | `ED` |
| 5 | `)` | Pop `+`, then discard `(` | Empty | `ED+` |
| 6 | `*` | Push operator | `*` | `ED+` |
| 7 | `C` | Copy operand | `*` | `ED+C` |
| 8 | `-` | Pop higher-precedence `*`, then push `-` | `-` | `ED+C*` |
| 9 | `B` | Copy operand | `-` | `ED+C*B` |
| 10 | `-` | Equal precedence, so keep the old `-` and push the new one | `- -` | `ED+C*B` |
| 11 | `A` | Copy operand | `- -` | `ED+C*BA` |
| 12 | End | Pop both remaining operators | Empty | `ED+C*BA--` |
| 13 | Reverse | Reverse the temporary output to get prefix | Empty | `--AB*C+DE` |