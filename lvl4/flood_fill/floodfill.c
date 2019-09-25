// Assignment name  : flood_fill
// Expected files   : *.c, *.h
// Allowed functions: -
// --------------------------------------------------------------------------------
// Write a function that takes a char ** as a 2-dimensional array of char, a
// t_point as the dimensions of this array and a t_point as the starting point.
// Starting from the given 'begin' t_point, this function 'colors' an entire zone
// by replacing characters inside by the character 'F'. A zone is an ensemble of
// the same character delimitated horizontally and vertically by other characters.
// The flood_fill function won't 'color' in diagonal.
// The flood_fill function will be prototyped like this:
// void  flood_fill(char **tab, t_point size, t_point begin);
// The t_point structure is available inside the "t_point.h" file attached to this
// assignment. We will use our "t_point.h" for graduation.
// Example :
// $> cat test_main.c
// #include "test_functions.h"
// #include "flood_fill.h"
// int main(void)
// {
//     char **area;
//     t_point size = { 8, 5 };
//     t_point begin = { 2, 2 };
//     char *zone[] = {
//         "11111111",
//         "10001001",
//         "10010001",
//         "10110001",
//         "11100001"
//     };
//     area = make_area(zone);
//     print_tab(area);
//     flood_fill(area, size, begin);
//     putc('\n');
//     print_tab(area);
//     return (0);
// }
// $> gcc flood_fill.c test_main.c test_functions.c -o flood_fill ; ./flood_fill
// 1 1 1 1 1 1 1 1
// 1 0 0 0 1 0 0 1
// 1 0 0 1 0 0 0 1
// 1 0 1 1 0 0 0 1
// 1 1 1 0 0 0 0 1
// 1 1 1 1 1 1 1 1
// 1 F F F 1 0 0 1
// 1 F F 1 0 0 0 1
// 1 F 1 1 0 0 0 1
// 1 1 1 0 0 0 0 1
// $>

#include "flood_fill.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
    t_point p;
    char c;

    c = tab[begin.y][begin.x];
    tab[begin.y][begin.x] = 'F';
    if (begin.y > 0 && tab[begin.y - 1][begin.x] == c)
    {
        p.x = begin.x;
        p.y = begin.y - 1;
        flood_fill(tab, size, p);
    }
    if (begin.x > 0 && tab[begin.y][begin.x - 1] == c)
    {
        p.x = begin.x - 1;
        p.y = begin.y;
        flood_fill(tab, size, p);
    }
    if ((begin.x < (size.x - 1)) && tab[begin.y][begin.x + 1] == c)
    {
        p.x = begin.x + 1;
        p.y = begin.y;
        flood_fill(tab, size, p);
    }
    if ((begin.y < (size.y - 1)) && tab[begin.y + 1][begin.x] == c)
    {
        p.x = begin.x;
        p.y = begin. y + 1;
        flood_fill(tab, size, p);
    }
}

#include <stdio.h>
#include <stdlib.h>

void print_tab(char **a, t_point size)
{
    int i;
    int j;
    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            printf("%c ", a[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}
char** make_area(char **a, t_point size)
{
    char **res;
    int  i, j;
    res = malloc(sizeof(char *) * size.y);
    i = 0;
    while (i < size.y)
    {
        res[i] = malloc(sizeof(char *) * (size.x + 1));
        j = 0;
        while (j < size.x)
        {
            res[i][j] = a[i][j * 2];
            j++;
        }
        i++;
    }
    return (res);
}
int main(void)
{
	t_point size = {8, 5};
	t_point begin = {2, 2};
    char **area;
	char *zone[] = {
		"1 0 0 0 0 0 0 0",
		"0 1 1 1 1 0 0 0",
		"0 1 1 1 0 0 0 0",
		"0 1 1 0 0 0 0 0",
		"0 0 0 0 0 0 0 0",
	};
    area = make_area((char **)zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}
