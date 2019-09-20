// Assignment name  : epur_str
// Expected files   : epur_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes a string, and displays this string with exactly one
// space between words, with no spaces or tabs either at the beginning or the end,
// followed by a \n.
//
// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.
//
// If the number of arguments is not 1, or if there are no words to display, the
// program displays \n.
//
// Example:
//
// $> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
// vous voyez c'est facile d'afficher la meme chose$
// $> ./epur_str " seulement          la c'est      plus dur " | cat -e
// seulement la c'est plus dur$
// $> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
// $
// $> ./epur_str "" | cat -e
// $
// $>

#include <unistd.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

int is_space(char s)
{
    if (s == ' ' || s == '\t' || s == '\n')
        return (1);
    return (0);
}

void eputstr(char *s)
{
    int len = ft_strlen(s);
    int i = 0;

    while (is_space(s[i]) == 1)
        i++;
    while (len && is_space(s[len - 1]) == 1)
        len--;
    while (len)
    {
        if (!is_space(s[i]) || (s[i + 1] && !is_space(s[i + 1])))
            write(1, &s[i], 1);
        i++;
        len--;
    }
}

int main(int ac, char **av)
{
    int i = 0;
    char *a;
    int j = 0;

    if (ac == 2 && av[1][i])
        eputstr(av[1]);
    write(1, "\n", 1);
    return (0);
}
