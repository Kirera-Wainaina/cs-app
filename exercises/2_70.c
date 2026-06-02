#include <stdio.h>
/*
 * Return 1 when x can be represented as an n-bit, 2's complement number;
 * Return 0 otherwise.
 * Assume 1 <= n <= w
 */

int fits_bits(int x, int n) {
    int num_bits = sizeof(int) * 8;
    int shifted = x << (num_bits - n) >> (num_bits - n);
    printf("\nx: 0x%08X, shifted: 0x%08X, n: %d\n", x, shifted, n);
    return shifted == x;
}



int main() {
    struct test_case {
        int x;
        int n;
        int expected;
    } tests[] = {
        {5, 3, 0},     // 101 needs 4 bits (0101)
        {-4, 3, 1},    // 100 is -4
        {-5, 3, 0},    // 1011 needs 4 bits
        {7, 4, 1},     // 0111 fits
        {-8, 4, 1},    // 1000 fits
        {8, 4, 0},     // 1000 is -8, so 8 needs 5 bits
        {0, 1, 1},     // 0 fits in 1 bit
        {-1, 1, 1},    // 1 fits in 1 bit
        {127, 8, 1},   // Fits in 8 bits
        {-128, 8, 1}   // Fits in 8 bits
    };

    for (int i = 0; i < 10; i++) {
        int result = fits_bits(tests[i].x, tests[i].n);
        printf("x: %d, n: %d | Result: %d | Expected: %d\n",
               tests[i].x, tests[i].n, result, tests[i].expected);
    }

    return 0;
}
