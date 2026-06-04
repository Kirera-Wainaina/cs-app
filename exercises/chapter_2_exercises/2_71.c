#include <stdio.h>

/*
 * The task is to operate on a data structure where 4 signed bytes
 * are packed into a 32-bit integer unsigned.
 * Bytes within the word are numbered from 0 to 3,
 * with byte 0 being the least significant byte.
 * Extract the designated byte and sign-extend it to 32 bits.
 */

/*
 * Declaration of data type where 4 bytes are packed into a
 * 32-bit integer unsigned.
 */

typedef unsigned int packed_t;

int xbyte(packed_t word, int bytenum) {
    int shifted = word << (8 * (3 - bytenum));
    return shifted >> 24;
}

int main() {
    struct test_case {
        packed_t word;
        int bytenum;
        int expected;
        char *desc;
    } tests[] = {
        {0x0000007F, 0, 127, "Positive max (byte 0)"},
        {0x00000080, 0, -128, "Negative min (byte 0)"},
        {0x00007F00, 1, 127, "Positive max (byte 1)"},
        {0x00008000, 1, -128, "Negative min (byte 1)"},
        {0xFF000000, 3, -1, "All ones (byte 3)"},
        {0x12345678, 0, 0x78, "Positive value (byte 0)"},
        {0x12345678, 2, 0x34, "Positive value (byte 2)"},
        {0xAABBCCDD, 0, (char)0xDD, "Negative value (0xDD)"},
        {0xAABBCCDD, 3, (char)0xAA, "Negative value (0xAA)"}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    printf("Running xbyte tests...\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < num_tests; i++) {
        int result = xbyte(tests[i].word, tests[i].bytenum);
        int success = (result == tests[i].expected);

        if (success) passed++;

        printf("[%s] %s\n", success ? "PASS" : "FAIL", tests[i].desc);
        printf("  Word: 0x%08X, Byte: %d\n", tests[i].word, tests[i].bytenum);
        printf("  Expected: %d (0x%08X), Got: %d (0x%08X)\n\n",
               tests[i].expected, tests[i].expected, result, result);
    }

    printf("--------------------------------------------------\n");
    printf("Result: %d/%d tests passed.\n", passed, num_tests);

    return 0;
}
