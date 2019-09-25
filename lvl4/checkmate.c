// Assignment name  : checkmate
// Expected files   : *.c, *.h
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
//
// Write a program who takes rows of a chessboard in argument and check if your
// King is in a check position.
//
// Chess is played on a chessboard, a squared board of 8-squares length with
// specific pieces on it : King, Queen, Bishop, Knight, Rook and Pawns.
// For this exercice, you will only play with Pawns, Bishops, Rooks and Queen...
// and obviously a King.
//
// Each piece have a specific method of movement, and all patterns of capture are
// detailled in the examples.txt file.
//
// A piece can capture only the first ennemy piece it founds on its capture
// patterns.
//
// The board have a variable size but will remains a square. There's only one King
// and all other pieces are against it. All other characters except those used for
// pieces are considered as empty squares.
//
// The King is considered as in a check position when an other enemy piece can
// capture it. When it's the case, you will print "Success" on the standard output
// followed by a newline, otherwise you will print "Fail" followed by a newline.
//
// If there is no arguments, the program will only print a newline.
//
// Examples:
//
// $> ./chessmate '..' '.K' | cat -e
// Fail$
// $> ./chessmate 'R...' '.K..' '..P.' '....' | cat -e
// Success$
// $> ./chessmate 'R...' 'iheK' '....' 'jeiR' | cat -e
// Success$
// $> ./chessmate | cat -e
// $
// $>

#include <stdlib.h>
#include <unistd.h>

// gcc checkmate.c && ./a.out '..R.' '.Q..' '..BK' '...P' | cat -e
// B = 3      Rook = 2 and Queen == 6   an P == 1

int		checkmate(int ac, char **av)
{
	int		y = 0;
	int		x = 0;
	int		len = 0;
	int		b = 0;
	int		a = 0;
	char	**m;

	// creating map
	while (ac-- > 1)
		len++;
	if (!(m = (char **)malloc(sizeof(char *) * len * (len + 1))))
		return (0);
	y = 0;
	while (y < len)
	{
		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		x = 0;
		while (av[y + 1][x])
		{
			m[y][x] = av[y + 1][x];
			if (m[y][x] == 'K')
			{
				a = x;
				b = y;
			}
			++x;
		}
		m[y][x] = 0;
		++y;
	}

	// checking if the King is endangered by a pawn
	if (m[b + 1][a + 1] == 'P' || m[b + 1][a - 1] == 'P')
		return (0);

	int		i = 0;
	while (i < len)
	{
		if (m[b][i] == 'Q' || m[i][a] == 'Q' || m[b][i] == 'R' || m[i][a] == 'R')
			return (0);
		if (i < b)
		{
			if (i < a && (m[b - i - 1][a - i - 1] == 'B' || m[b - i - 1][a - i - 1] == 'Q') )
				return (0);
			if (a + i < len && (m[b - i - 1][a + i + 1] == 'B' || m[b - i - 1][a + i + 1] == 'Q'))
				return (0);
		}
		if (b + i < len)
		{
			if (i < a && (m[b + i + 1] [a - i - 1] == 'B' || m[b + i + 1] [a - i - 1] == 'Q'))
				return (0);
			if (a + i < len && (m[b + i + 1] [a + i + 1] == 'B' || m[b + i + 1] [a + i + 1] == 'Q' ))
				return (0);
		}
		i++;
	}
	return (1);
}


void	print(int ac, char **av)
{
	int		len;
	int		x;
	int		y;
	char	**m;

	// creating map
	while (ac-- > 1)
		len++;
	if (!(m = (char **)malloc(sizeof(char *) * len * (len + 1))))
		return ;
	y = 0;
	while (y < len)
	{
		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))
			return ;
		x = 0;
		while (av[y + 1][x])
		{
			m[y][x] = av[y + 1][x];
			++x;
		}
		m[y][x] = 0;
		++y;
	}
	// printing map
	y = 0;
	while (y < len)
	{
		write(1, m[y++], len);
		write(1, "\n", 1);
	}
}


int		main(int ac, char **av)
{
	if (ac > 1 && !checkmate(ac, av))
		write(1, "Success\n", 8);
	else
		write(1, "Fail\n", 5);
	print(ac, av);
	return (0);
}
