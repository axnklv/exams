// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------
//
// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.
//
// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.
//
// Yes, the examples are right.
//
// Examples:
//
// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    char a;
	if (n > 9)
		ft_putnbr(n / 10);
    a = n % 10 + '0';
	ft_putchar(a);
}

int ft_atoi(char *s)
{
    int i = 0;
    int a = 0;

    while (s[i] >= '0' && s[i] <= '9')
    {
            a = a * 10 + s[i] - '0';
            i++;
    }
    return (a);
}

int prime(int n)
{
    int i = 2;
    int k = 0;
    while (i < n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void add_prime_sum(int n)
{
    int i = 2;
    int sum = 0;

    while(i <= n)
    {
        if (prime(i) == 1)
            sum = sum + i;
        i++;
    }
    if (n == 1)
        sum = 0;
    ft_putnbr(sum);
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2 && av[1][i] > 0)
        add_prime_sum(ft_atoi(av[1]));
    write(1, "\n", 1);
    return (0);
}
