// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string and displays its last word followed by a \n.
//
// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.
//
// If the number of parameters is not 1, or there are no words, display a newline.
//
// Example:
//
// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
            i++;
        i--;
        while (is_space(av[1][i]))
            i--;
        while (av[1][i] && !is_space(av[1][i]))
            i--;
        i++;
        while (av[1][i] && !is_space(av[1][i]))
        {
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
