// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write the following function:
//
// void sort_int_tab(int *tab, unsigned int size);
//
// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.
//
// Doubles must be preserved.
//
// Input is always coherent.

void	sort_int_tab(int *tab, unsigned int size)
{
	int				temp;
	unsigned int 	i;
	unsigned int 	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

int		main(void)
{
	int tab[] = {0, -1, 2, 3, -7};
	unsigned int size = 5;
	unsigned int j = 0;

	while (j < size)
	{
		printf("element %d: %d\n", j + 1, tab[j]);
		j++;
	}

	sort_int_tab(tab, size);
	printf("\n");

	unsigned int i = 0;
	while (i < size)
	{
		printf("element %d: %d\n", i + 1, tab[i]);
		i++;
	}
	return 0;
}
