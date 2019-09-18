// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.
//
// Your function must be declared as follows:
//
// unsigned char	reverse_bits(unsigned char octet);
//
// Example:
//
//   1 byte
// _____________
//  0100  0001
//      ||
//      \/
//  1000  0010

#include <unistd.h>

unsigned char reverse_bits2(unsigned char b)
{
	unsigned char	r = 0;
	unsigned		char_len = 8;

	while (char_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

unsigned char   reverse_bits(unsigned char octet)
{
	return  (((octet >> 0) & 1) << 7) | \
			(((octet >> 1) & 1) << 6) | \
			(((octet >> 2) & 1) << 5) | \
			(((octet >> 3) & 1) << 4) | \
			(((octet >> 4) & 1) << 3) | \
			(((octet >> 5) & 1) << 2) | \
			(((octet >> 6) & 1) << 1) | \
			(((octet >> 7) & 1) << 0);
}

int	main(void)
{
	unsigned char c;

	c = 't';
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits2(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
