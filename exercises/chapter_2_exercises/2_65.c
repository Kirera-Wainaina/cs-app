#include <stdio.h>

/*
 * Return 1 when x contains an odd number of 1s; 0 otherwise.
 * Assume w = 32
 * Follow rules on page 128
 * Your code should contain a total of at most 12
 * arithmetic, bitwise, and logical operations.
 */

int odd_ones(unsigned x) {
    unsigned char *p = (unsigned char *) &x;
    // reduce to 8 meaningful bits
    unsigned char reduced = (p[0] ^ p[1]) ^ (p[2] ^ p[3]);
    // reduce to 4 meaningful bits
    reduced = (reduced & 0xF) ^ (reduced >> 4); // reduce to 4 bits
    // reduce to 2 meaningful bits
    reduced = (reduced & 0x3) ^ (reduced >> 2);
    // reduce to 1 meaningful bit
    reduced = (reduced & 0x1) ^ (reduced >> 1);

    return reduced;
}

/*
 * My solution: I figured out that when you use XOR you can
 * cancel out pairs of 1s, leaving only odd occurrences of 1s.
 * You do that while reducing the number of bits from 32 to 16,
 * then from 16 to 8, then from 8 to 4, then from 4 to 2, and finally to 1.
 */

int main() {
    unsigned test_cases[] = {
        0x0,          /* 0 ones (even) -> 0 */
        0x1,          /* 1 one (odd) -> 1 */
        0x3,          /* 2 ones (even) -> 0 */
        0x7,          /* 3 ones (odd) -> 1 */
        0xF,          /* 4 ones (even) -> 0 */
        0xFFFFFFFF,   /* 32 ones (even) -> 0 */
        0x80000000,   /* 1 one (odd) -> 1 */
        0x55555555,   /* 16 ones (even) -> 0 */
        0xAAAAAAAA,   /* 16 ones (even) -> 0 */
        0x10101011    /* 5 ones (odd) -> 1 */
    };

    int i;
    int expected[] = {0, 1, 0, 1, 0, 0, 1, 0, 0, 1};
    for (i = 0; i < 10; i++) {
        printf("Test Case 0x%08X: result %d, expected %d\n", test_cases[i], odd_ones(test_cases[i]), expected[i]);
    }

    return 0;
}
