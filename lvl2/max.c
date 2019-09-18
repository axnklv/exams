// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write the following function:
//
// int		max(int* tab, unsigned int len);
//
// The first parameter is an array of int, the second is the number of elements in
// the array.
//
// The function returns the largest number found in the array.
//
// If the array is empty, the function returns 0.

int max(int *tab, unsigned int len)
{
    int i;
    int max;

    i = 0;
    if (!tab)
        return (0);
    if (len < 1)
        return (0);
    max = tab[0];
    while (len > 0)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
        len--;
    }
    return (max);
}

int		main(void)
{
	int	*tab;

	if (!(tab = (int*)malloc(sizeof(int) * 3)))
		return (0);
	tab[0] = 7;
	tab[1] = 16;
	tab[2] = 4;
	printf("%d", max(tab, 3));
	return (0);
}
