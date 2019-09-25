// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
//
// Write a program that takes a string and displays this string after rotating it
// one word to the left.
//
// Thus, the first word becomes the last, and others stay in the same order.
//
// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.
//
// Words will be separated by only one space in the output.
//
// If there's less than one argument, the program displays \n.
//
// Example:
//
// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring | cat -e
// $
// $>

#include <unistd.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *s)
{
	int		i = 0;
	int		first_word_length = 0;

	while (s[i])
	{
		while (is_space(s[i]))
			i++;
		if (s[i] && !is_space(s[i]))
		{
			// if it's the beggining
			if (first_word_length == 0)
				// keep the length of first word for later
				while (s[i] && !is_space(s[i++]))
					first_word_length++;
			else
			{
				// for other words, just write it to stdout (+ one whitespace)
				while (s[i] && !is_space(s[i]) && write(1, &s[i++], 1));
				write(1, " ", 1);
			}
		}
	}
	// write first word
	i = 0;
	while (is_space(s[i]))
		i++;
	while (first_word_length--)
		write(1, &s[i++], 1);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
