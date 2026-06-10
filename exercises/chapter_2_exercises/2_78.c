/*
 * Divide by power of 2. Assume 0 <= k < w - 1
 */

#include <stdio.h>


/*
 * The solution works but it's slightly the rounding is slightly confusing
 */
int divide_power2(int x, int k) {
    int is_positive = ~((int)(0x80000000 & x) >> 31);
    return ((is_positive) & x >> k) | ((~is_positive) & (x + (1 << k) - 1) >> k);
}

void run_test(int x, int k) {
    int result = divide_power2(x, k);
    int expected = x / (1 << k);
    printf("Testing x = %11d, k = %2d: Expected %11d, Got %11d [%s]\n",
           x, k, expected, result, (result == expected) ? "PASS" : "FAIL");
}

int main() {
    printf("Positive numbers:\n");
    run_test(128, 2);
    run_test(128, 7);
    run_test(1023, 1);

    printf("\nNegative numbers:\n");
    run_test(-128, 2);
    run_test(-128, 7);
    run_test(-5, 1);
    run_test(-1023, 1);

    return 0;
}
