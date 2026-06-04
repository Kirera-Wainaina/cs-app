/*
 * Determine whether arguments can be subtracted without overflow.
 * Return 1 if x - y does not overflow, 0 otherwise.
 */

#include <stdio.h>
#include <limits.h>

int tsub_ok(int x, int y) {
    int result = x - y;
    int x_mask = x >> 31;
    int y_mask = y >> 31;
    int result_mask = result >> 31;
    // If x and y have the same sign, then that's immediately true
    // Otherwise, the result sign should match the sign of x
    return (x_mask == y_mask) || (result_mask == x_mask);
}


int main() {
    /* Test cases for tsub_ok */
    printf("tsub_ok(0, 0): %d (expected 1)\n", tsub_ok(0, 0));
    printf("tsub_ok(INT_MIN, 1): %d (expected 0)\n", tsub_ok(INT_MIN, 1));
    printf("tsub_ok(INT_MAX, -1): %d (expected 0)\n", tsub_ok(INT_MAX, -1));
    printf("tsub_ok(INT_MIN, INT_MIN): %d (expected 1)\n", tsub_ok(INT_MIN, INT_MIN));
    printf("tsub_ok(INT_MAX, INT_MAX): %d (expected 1)\n", tsub_ok(INT_MAX, INT_MAX));
    printf("tsub_ok(-10, INT_MAX): %d (expected 0)\n", tsub_ok(-10, INT_MAX));
    printf("tsub_ok(10, INT_MIN): %d (expected 0)\n", tsub_ok(10, INT_MIN));
    printf("tsub_ok(INT_MAX, 1): %d (expected 1)\n", tsub_ok(INT_MAX, 1));
    printf("tsub_ok(INT_MIN, -1): %d (expected 1)\n", tsub_ok(INT_MIN, -1));

    return 0;
}
