/*
 * Do rotating left shift. Assume 0 <= n < w.
 * Examples when x = 0x12345678 and w = 32:
 * n = 4  ->  0x23456781
 * n = 20 ->  0x67812345
 */

#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
    unsigned size = sizeof(unsigned) * 8;
    unsigned rotated = x >> (size - n - 1) >> 1;
    unsigned anchor = x << n;
    return rotated + anchor;
}

int main() {
    unsigned x = 0x12345678;

    printf("Test 1: n = 0 | Expected: 0x12345678 | Result: 0x%08x\n", rotate_left(x, 0));
    printf("Test 2: n = 4 | Expected: 0x23456781 | Result: 0x%08x\n", rotate_left(x, 4));
    printf("Test 3: n = 8 | Expected: 0x34567812 | Result: 0x%08x\n", rotate_left(x, 8));
    printf("Test 4: n = 12 | Expected: 0x45678123 | Result: 0x%08x\n", rotate_left(x, 12));
    printf("Test 5: n = 16 | Expected: 0x56781234 | Result: 0x%08x\n", rotate_left(x, 16));
    printf("Test 6: n = 20 | Expected: 0x67812345 | Result: 0x%08x\n", rotate_left(x, 20));
    printf("Test 7: n = 24 | Expected: 0x78123456 | Result: 0x%08x\n", rotate_left(x, 24));
    printf("Test 8: n = 28 | Expected: 0x81234567 | Result: 0x%08x\n", rotate_left(x, 28));
    printf("Test 9: n = 31 | Expected: 0x091a2b3c | Result: 0x%08x\n", rotate_left(x, 31));

    unsigned y = 0xF000000F;
    printf("Test 10: n = 4 | Expected: 0x000000FF | Result: 0x%08x\n", rotate_left(y, 4));

    return 0;
}
