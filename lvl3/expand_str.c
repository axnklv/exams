// Assignment name  : expand_str
// Expected files   : expand_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string and displays it with exactly three spaces
// between each word, with no spaces or tabs either at the beginning or the end,
// followed by a newline.
//
// A word is a section of string delimited either by spaces/tabs, or by the
// start/end of the string.
//
// If the number of parameters is not 1, or if there are no words, simply display
// a newline.
//
// Examples:
//
// $> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
// vous   voyez   c'est   facile   d'afficher   la   meme   chose$
// $> ./expand_str " seulement          la c'est      plus dur " | cat -e
// seulement   la   c'est   plus   dur$
// $> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
// $
// $> ./expand_str "" | cat -e
// $
// $>

#include <unistd.h>

// int		ft_isblank(char c)
// {
// 	return ((c == ' ' || c == '\t') ? 1 : 0);
// }
//
// void	expand_str(char *s)
// {
// 	int	i = 0;
// 	int	wc = 0;
//
// 	while (s[i])
// 		if (!ft_isblank(s[i++]) && (!wc || ft_isblank(s[i - 2])))
// 			++wc;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (!ft_isblank(s[i++]) && wc--)
// 		{
// 			write (1, &s[i - 1], 1);
// 			while (s[i] && !ft_isblank(s[i]) && write(1, &s[i++], 1));
// 			(wc) ? write(1, "   ", 3) : 0;
// 		}
// 	}
// }
//
// int		main(int ac, char **av)
// {
// 	if (ac == 2)
// 		expand_str(av[1]);
// 	write(1, "\n", 1);
// }

int		main(int argc, char const *argv[])
{
	int		i;
	int		flg;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i += 1;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flg = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flg)
					write(1, "   ", 3);
				flg = 0;
				write(1, &argv[1][i], 1);
			}
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// int main()
// {
//     int i = 0;
//
//     if (ac == 2 && av[1])
//     {
//
//     }
//     write(1, "\n", 1);
//     return (0);
// }
