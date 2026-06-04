#include <stdio.h>

/*
 * Generate mask indicating leftmost 1 in x.
 * Assume w = 32
 * For example, 0xFF00 -> 0x8000, 0x6600 -> 0x4000
 * If x = 0, return 0
 * Your function should follow the bit-level integer coding rules (page 128)
 * Your code should contain a total of at most 15 arithmetic,
 * bitwise, and logical operations.
 */

int leftmost_one(unsigned x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return (x ^ (x >> 1));
}

/*
 * As you bit shift to the right, you are "switching on" the other bits
 * to the right. once all the values to the right of the most significant
 * bit are 1s then you do a final bit shift once more and an XOR which
 * leaves the significant bit as 1.
 *
 * This was a difficult problem to solve.
 */

int main() {
    struct {
        unsigned input;
        unsigned expected;
    } tests[] = {
        {0x00000000, 0x00000000},
        {0x0000FF00, 0x00008000},
        {0x00006600, 0x00004000},
        {0x00000001, 0x00000001},
        {0x80000000, 0x80000000},
        {0xFFFFFFFF, 0x80000000},
        {0x00000008, 0x00000008},
        {0x0000000F, 0x00000008},
        {0x55555555, 0x40000000},
        {0x12345678, 0x10000000}
    };

    for (int i = 0; i < 10; i++) {
        unsigned result = leftmost_one(tests[i].input);
        printf("Test %d: Input: 0x%08x | Expected: 0x%08x | Result: 0x%08x | %s\n",
               i + 1, tests[i].input, tests[i].expected, result,
               (result == tests[i].expected) ? "PASS" : "FAIL");
    }

    return 0;
}
