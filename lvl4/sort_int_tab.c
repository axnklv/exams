Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int j = 0;
	int temp;

	while (i < size)
	{
		while (j < size - 1)
		{
			if (tab[j] < tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			} 
			j++;
		}
		i++;
	}
}