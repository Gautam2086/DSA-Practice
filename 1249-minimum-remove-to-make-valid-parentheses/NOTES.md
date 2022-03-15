Valid parentheses condition:
1. the no.of close bracket should be equal to no.of open brackets when iterating from left to right
2. the no.of open bracket should be equal to no.of close brackets when iterating from right to left
​
Solution With Stack
==>Push '(' into a stack and whenever ')' appears in the string, try to pop '(' from stackif exists.
==> If '(' does not exist, then erase ')' from string.
==> After parsing the entire string, erase extra '(' present in stack from string.