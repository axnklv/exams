// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.
//
// The display will be followed by a \n.
//
// If the number of arguments is not 2, the program displays \n.
//
// Examples:
//
// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $
// abcdef cda

#include <unistd.h>

char *inter(char *s1, char *s2)
{
    int i = 0;
    int k = 0;
    int j;
    char *a = s2;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                a[k] = s1[i];
                k++;
                break ;
            }
            j++;
        }
        i++;
    }
    a[k] = '\0';
    return (a);
}

char *change_double(char *s)
{
    int i = 0;
    int j = 0;
    char *a = s;

    while (a[i])
    {
        j = i + 1;
        while (a[j])
        {
            if (a[i] == a[j])
                a[j] = '\n';
            j++;
        }
        i++;
    }
    return (a);
}

char *delete_double(char *s)
{
    int i = 0;
    int j = 0;
    char *a = s;
    while (a[i])
    {
        if (a[i] == '\n')
            i++;
        else
        {
            a[j] = a[i];
            j++;
            i++;
        }
    }
    a[j] = '\0';
    return (a);
}

int main(int ac, char **av)
{
    char *a;
    int i = 0;

    if (ac == 3)
    {
        a = inter(av[1], av[2]);
        a = change_double(a);
        a = delete_double(a);
        while (a[i])
        {
            write(1, &a[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
