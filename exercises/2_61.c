#include <stddef.h>
#include <stdio.h>

int any_bit_is_0(int x) {
    return !!~x;
}

int any_bit_is_1(int x) {
    return !!x;
}

int any_bit_in_least_significant_byte_is_1(int x) {
    return !!(x & 0xFF);
}

int any_bit_in_most_significant_byte_is_0(int x) {
    return !!(~x & 0xFF000000);
}

int main() {
	// printf("%x\n", replace_byte(0x89ABCDEF, 2, 0xFF));
	// printf("%x\n", yield_x_and_y());
	printf("%d\n", any_bit_is_0(0xFFFFFFFF));
	return 0;
}
