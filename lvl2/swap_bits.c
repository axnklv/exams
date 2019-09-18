//
// Assignment name  : swap_bits
// Expected files   : swap_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that takes a byte, swaps its halves (like the example) and
// returns the result.
//
// Your function must be declared as follows:
//
// unsigned char	swap_bits(unsigned char octet);
//
// Example:
//
// 1 byte
// _____________
// 0100 | 0001
//    \ /
//    / \
// 0001 | 0100

#include <unistd.h>

unsigned char	swap_bits(unsigned char c)
{
	return ((c >> 4) | (c << 4));
}

int		main(void)
{
	char c;

	c = 't';
	write(1, &c, 1);
    write(1, "\n", 1);
	c = swap_bits(c);
	write(1, &c, 1);
	return (0);
}
