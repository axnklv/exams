//
// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
//
// Write the following function:
//
// int     *ft_range(int start, int end);
//
// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.
//
// Examples:
//
// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int len;
    int *s;
    int i = 0;

    if (end >= start)
        len = end - start + 1;
    else
        len = start - end + 1;
    if (!(s = (int *)malloc(sizeof(int) * (len + 1))))
        return (NULL);
    while (i < len)
    {
        if (end >= start)
        {
            s[len] = start + 1;
            i++;
        }
        else
        {
            s[i] = start - 1;
            i++;
        }
    }
    return (s);
}
