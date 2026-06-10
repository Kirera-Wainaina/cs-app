/*
 * Write a function that computes 3 * x / 4
 */

#include <stdio.h>

/**
 * Lesson learned: When doing bitwise division, remember to add a bias
 * of 2^k - 1 to the numerator before shifting right
 * This is because int division rounds towards zero, so we need to add a bias
 * to ensure the result is rounded up correctly for negative numbers
 */
int mul3div4(int x) {
    int is_positive = ~((int)(0x80000000 & x) >> 31);
    return ((is_positive) & ((x << 1) + x) >> 2) | ((~is_positive) & ((x << 1) + x + 3) >> 2);
}

/**
 * Cleaner alternative suggested by AI
 */

int mul3div4_(int x) {
    int three_x = (x << 1) + x;
    // This mask is 0xFFFFFFFF if negative, 0x00000000 if positive
    int is_neg_mask = (three_x >> 31);
    // This becomes 3 if negative, 0 if positive
    int bias = is_neg_mask & 3;

    return (three_x + bias) >> 2;
}

void run_test(int x) {
    int result = mul3div4(x);
    int expected = (int)((3LL * x) / 4);
    printf("Testing x = %11d: Expected %11d, Got %11d [%s]\n",
           x, expected, result, (result == expected) ? "PASS" : "FAIL");
}

int main() {
    printf("Positive numbers:\n");
    run_test(4);    // 3*4/4 = 3
    run_test(5);    // 3*5/4 = 3.75 -> 3
    run_test(100);  // 300/4 = 75

    printf("\nNegative numbers:\n");
    run_test(-4);   // -12/4 = -3
    run_test(-5);   // -15/4 = -3.75 -> -3
    run_test(-100); // -300/4 = -75

    return 0;
}
