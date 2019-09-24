// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
//
// Write a program that takes a string as a parameter, and prints its words in
// reverse order.
//
// A "word" is a part of the string bounded by spaces and/or tabs, or the
// begin/end of the string.
//
// If the number of parameters is different from 1, the program will display
// '\n'.
//
// In the parameters that are going to be tested, there won't be any "additional"
// spaces (meaning that there won't be additionnal spaces at the beginning or at
// the end of the string, and words will always be separated by exactly one space).
//
// Examples:
//
// $> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
// l'indifference de celui precede mepris du temps le$
// $> ./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "il contempla le mont" | cat -e
// mont le contempla il$
// $> ./rev_wstr | cat -e
// $
// $>

#include <unistd.h>
#include <stdlib.h>


int		ft_strlen(char *str)
{
	int	len = 0;
    int i = 0;

	while (str[i++])
		len++;
	return (len);
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	print_reverse(char *str)
{
	int fast;	// the start of a word
	int slow;	// the end of a word
	int curr;	// running through the word so we can write it

	fast = ft_strlen(str) - 1;
	slow = fast;
	curr = fast;

	while (fast >= 0)
	{
		slow = fast;
		curr = fast;
		while (fast >= 0 && !is_space(str[fast]))
			fast--;
		fast++;
		curr = fast;
		while (curr <= slow)
		{
			write(1, &str[curr], 1);
			curr++;
		}
		if (fast > 0)
			write(1, " ", 1);
		fast--;
		fast--;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_reverse(av[1]);
	write(1, "\n", 1);
	return (1);
}
