/*
 * Fill in the code for the following C functions.
 * Function `srl` performs a logical right shift using an
 * arithmetic right shift (given by value `xsra`), followed by
 * other operations not including right shifts or division.
 */

#include <limits.h>
#include <stddef.h>
unsigned srl(unsigned x, int k) {
   /* Perform shift arithmetically */
   unsigned xsra = (int) x >> k;
   return xsra << k >> k;
}

unsigned srl_2(unsigned x, int k) {
   /* Perform shift arithmetically */
   unsigned xsra = (int) x >> k; // Line given by textbook
   unsigned num_bits = sizeof(x) * 8;
   unsigned mask = ~(UINT_MAX << (num_bits - k));
   return xsra & mask;
}


/*
 * Function `sra` performs an arithmetic right shift using a logical
 * right shift (given by value xsrl), followed by other operations
 * not including right shifts or division.
 */
int sra(int x, int k) {
   /* Perform shift logically */
   int xsrl = (unsigned) x >> k;
   unsigned num_bits = sizeof(x) * 8;
   unsigned msb = x & (1 << (num_bits - 1));
   int mask = (signed) ~(!!msb - 1) << (num_bits - k - 1) << 1;
   return xsrl | mask;
}
