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

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    else
        return (0);
}

int len(char *c)
{
    int i = 0;
    while (c[i])
        i++;
    return (i);
}

void reverse(char *s)
{
    int start;
    int curr;
    int end;

    start = len(s) - 1;
    end = start;
    curr = start;

    while (start >= 0)
    {
        end = start;
        curr = start;

        while (start >= 0 && is_space(s[start]) == 0)
            start--;
        curr = start + 1;
        while (curr <= end)
        {
            write(1, &s[curr], 1);
            curr++;
        }
        if (start > 0)
            write(1, " ", 1);
        start--;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        reverse(av[1]);
    write(1, "\n", 1);
    return (0);
}
