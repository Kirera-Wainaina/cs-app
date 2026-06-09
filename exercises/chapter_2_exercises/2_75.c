#include <stdio.h>

/*
 * We want to compute the high-order bits of the product
 * of two signed integers x and y.
 */

int signed_high_prod(int x, int y) {
    long result = (long)x * (long)y;
    return result >> 32;
}

/*
 * We want to compute the high-order bits of the product
 * of two unsigned integers x and y.
 *
 * Thoughts: Implementing this was a bit confusing because when you
 * derive the formula using math, it looks like:
 *      unsigned_high_prod(int x, int y) = signed_high_prod(x, y) + x * y_w-1 + x_w-1 * y
 *
 * The confusion is that it makes sense that x and y on the right hand side
 * are signed because you are deriving x' and y' which are the unsigned
 * high-order bits of x and y. To make it easier on yourself, think of x and y
 * as bits not actual values of x and y then treat everything as unsigned, because
 * "unsigned infects everything" and you are calculating an unsigned result anyway.
 *
 */
unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int shp = signed_high_prod((int)x, (int)y);
    unsigned x_msb = x >> 31;
    unsigned y_msb = y >> 31;


    return (unsigned)shp + x * y_msb + x_msb * y;
}

int main() {
    printf("x . y = %08X\n", unsigned_high_prod(7, 7));
}
