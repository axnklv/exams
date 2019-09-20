// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that displays the number of arguments passed to it, followed by
// a newline.
//
// If there are no arguments, just display a 0 followed by a newline.
//
// Example:
//
// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
    if (n > 9)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int main(int ac, char **av)
{
    ft_putnbr(ac - 1);
    write(1, "\n", 1);
    return (0);
}
