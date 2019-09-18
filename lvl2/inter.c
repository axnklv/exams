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
    int j;
    int k = 0;
    char *a;
    a = s2;
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
    a[k] =  '\0';
    return (a);
}

char *change_double(char *s)
{
    int i = 0;
    int j;
    int k = 0;
    char *a;
    a = s;
    while (s[i])
    {
        j = i + 1;
        while (s[j])
        {
            if (s[i] == s[j])
                s[j] = '\n';
            j++;
        }
        i++;
    }
    return (s);
}

char *delete_double(char *s)
{
    char *a;
    a = s;
    int i = 0;
    int k = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            i++;
        else
        {
            a[k] = s[i];
            k++;
            i++;
        }
    }
    a[k] = '\0';
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
            write(1, &a[i++], 1);
    }
    write(1, "\n", 1);
    return (0);
}
