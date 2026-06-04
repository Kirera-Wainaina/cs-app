#include <stdio.h>

/*
 * Return 1 when any odd bit of x equals 1; 0 otherwise.
 * Assume w=32
 */

int any_odd_one(unsigned x) {
    return !!(x & 0xAAAAAAAA);
}

int main() {
    /* Test variations for any_odd_one */
    unsigned tests[6] = {
        0x00000000, /* Case 0: No bits set (Result: 0) */
        0x55555555, /* Case 1: All even bits set (Result: 0) */
        0x00000002, /* Case 2: One odd bit set (Result: 1) */
        0xAAAAAAAA, /* Case 3: All odd bits set (Result: 1) */
        0x00000001, /* Case 4: Only bit 0 (even) set (Result: 0) */
        0x80000000  /* Case 5: Only bit 31 (odd) set (Result: 1) */
    };

    int expected[6] = {0, 0, 1, 1, 0, 1};

    for (int i = 0; i < 6; i++) {
        printf("Test %d: x = 0x%08X, Expected = %d, Result = %d\n", i, tests[i], expected[i], any_odd_one(tests[i]));
    }

    return 0;
}
