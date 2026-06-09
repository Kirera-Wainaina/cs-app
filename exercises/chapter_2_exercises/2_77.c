/*
 * You are given a task to generate code to multiply integer variable x by
 * various different constant factors K.
 * To be efficient, we want to use only operations +, -, and <<.
 */

#include <stdio.h>

int multiply_k_17(int x) {
    // multiply by 17
    return (x << 4) + x;
}

int multiply_k_minus_7(int x) {
    // multiply by -7
    int k = -7;
    int multiply_by_7 = (x << 3) - x;
    return multiply_by_7 - (multiply_by_7 << 1);
}

int multiply_k_60(int x) {
    // multiply by 60
    return (x << 6) - (x << 2);
}

int multiply_k_minus_112(int x) {
    // multiply by -112
    int multiple = ((x << 7) - (x << 4));
    return multiple - (multiple << 1);
}

void run_test(int x) {
    printf("Testing x = %d:\n", x);
    printf("  17 * x:       Expected %11d, Got %11d [%s]\n", 17 * x, multiply_k_17(x), (17 * x == multiply_k_17(x)) ? "PASS" : "FAIL");
    printf("  -7 * x:       Expected %11d, Got %11d [%s]\n", -7 * x, multiply_k_minus_7(x), (-7 * x == multiply_k_minus_7(x)) ? "PASS" : "FAIL");
    printf("  60 * x:       Expected %11d, Got %11d [%s]\n", 60 * x, multiply_k_60(x), (60 * x == multiply_k_60(x)) ? "PASS" : "FAIL");
    printf("  -112 * x:     Expected %11d, Got %11d [%s]\n", -112 * x, multiply_k_minus_112(x), (-112 * x == multiply_k_minus_112(x)) ? "PASS" : "FAIL");
    printf("\n");
}

int main() {
    run_test(1);
    run_test(10);
    run_test(-5);
    run_test(100);
    return 0;
}
