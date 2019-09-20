// Assignment name  : rstr_capitalizer
// Expected files   : rstr_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes one or more strings and, for each argument, puts
// the last character of each word (if it's a letter) in uppercase and the rest
// in lowercase, then displays the result followed by a \n.
//
// A word is a section of string delimited by spaces/tabs or the start/end of the
// string. If a word has a single letter, it must be capitalized.
//
// If there are no parameters, display \n.
//
// Examples:
//
// $> ./rstr_capitalizer | cat -e
// $
// $> ./rstr_capitalizer "Premier PETIT TesT" | cat -e
// premieR petiT tesT$
// $> ./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
// deuxiemE tesT uN peU moinS  facilE$
//    attentioN c'esT paS duR quanD memE$
// alleR uN dernieR 0123456789pouR lA routE    E $
// $>

#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && 'Z' >= str[i])
			str[i] += 32;
		if ((str[i] >= 'a' && 'z' >= str[i]) && (str[i + 1] == ' ' || \
			str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i], 1);
        i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc < 1)
		write (1, "\n", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i += 1;
		}
	}
	return (0);
}
