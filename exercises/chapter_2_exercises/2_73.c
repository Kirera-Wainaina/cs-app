/**
 * Addition that saturates to TMin and TMax
 */

#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y) {
    int result = x + y;
    long long_result = (long)x + (long)y;
    int is_overflow = long_result != (long_result << 32 >> 32);
    int is_overflow_mask = ~is_overflow << 31 >> 31;
    int saturation_value = ((int)(result & 0x80000000) >> 31) ^ 0x80000000;

    return (is_overflow_mask & result) |
    (~is_overflow_mask & saturation_value);
}

int main() {
    struct test_case {
        int x;
        int y;
        int expected;
        char *desc;
    } tests[] = {
        {100, 200, 300, "Normal addition"},
        {INT_MAX, 1, INT_MAX, "Positive saturation"},
        {INT_MAX - 5, 10, INT_MAX, "Positive saturation (small)"},
        {INT_MIN, -1, INT_MIN, "Negative saturation"},
        {INT_MIN + 5, -10, INT_MIN, "Negative saturation (small)"},
        {INT_MAX, INT_MAX, INT_MAX, "Double positive max"},
        {INT_MIN, INT_MIN, INT_MIN, "Double negative min"},
        {INT_MAX, INT_MIN, -1, "Opposite signs (no overflow)"},
        {0, 0, 0, "Zero"}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    printf("Running saturating_add tests...\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int result = saturating_add(tests[i].x, tests[i].y);
        int success = (result == tests[i].expected);

        if (success) passed++;

        printf("[%s] %s\n", success ? "PASS" : "FAIL", tests[i].desc);
        printf("  x: %d (0x%X), y: %d (0x%X)\n", tests[i].x, tests[i].x, tests[i].y, tests[i].y);
        printf("  Expected: %d (0x%X), Got: %d (0x%X)\n\n",
               tests[i].expected, tests[i].expected, result, result);
    }

    printf("--------------------------------------------------\n");
    printf("Result: %d/%d tests passed.\n", passed, num_tests);

    return 0;
}
