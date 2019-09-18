// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------
//
// Write a function that converts the string argument str to an integer (type int)
// and returns it.
//
// It works much like the standard atoi(const char *str) function, see the man.
//
// Your function must be declared as follows:
//
// int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	int number;
	int sign;
	int i;


	i = 0;
	sign = 1;
	number = 0;
	if (str == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		   || str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (sign * number);
}

int	main()
{
	char	n[40] = "";
	int		i1 = atoi(n);
	int		i2 = ft_atoi(n);
	printf("%d\n", i1);
    printf("%d\n", i2);
}
