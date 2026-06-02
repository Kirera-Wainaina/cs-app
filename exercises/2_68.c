#include <stdio.h>

/*
 * Mask with least significant bits n set to 1.
 * Example: n = 6, result = 0x3f (binary: 00111111)
 * n = 17, result = 0x1ffff (binary: 0001111111111111)
 * Assume 1 <= n <= w
 */

int lower_one_mask(int n) {
    return ~(~0 << (n - 1) << 1);
}

int main() {
    struct {
        int n;
        int expected;
    } tests[] = {
        {6, 0x3f},
        {17, 0x1ffff},
        {1, 0x1},
        {32, 0xffffffff}
    };

    for (int i = 0; i < 4; i++) {
        int result = lower_one_mask(tests[i].n);
        printf("n = %2d | Expected: 0x%08x | Result: 0x%08x | %s\n",
               tests[i].n, tests[i].expected, result,
               (result == tests[i].expected) ? "PASS" : "FAIL");
    }

    return 0;
}
