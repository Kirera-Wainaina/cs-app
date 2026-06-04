# Rules

## Assumptions
- Integers are represented in two's complement form.
- Right shifts are arithmetic shifts.
- Data type int is w bits long. For some of the problems, you will be given the number of bits w, but otherwise your code should work as long as
w is a multiple of 8. You can use the epxression `sizeof(int)<<3` to compute w.

## Forbidden
- Conditionals (`if` or `?:`), loops, switch statements, function calls, and macro invocations.
- Division, modulus, and multiplication.
- Relative comparisons (`<`, `>`, `<=`, `>=`).

## Allowed
- All bit level and logical operations.
- Left and right shifts, but only with the shift amounts between 0 and w-1.
- Addition and subtraction.
- Equality (`==`) and inequality (`!=`). Some of the problems do not allow these.
- Casting between data types `int` and `unsigned`, either explicitly or implicitly.
