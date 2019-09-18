// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that reverses (in-place) a string.
//
// It must return its parameter.
//
// Your function must be declared as follows:
//
// char    *ft_strrev(char *str);

char *ft_strrev(char *str)
{
    int i;
    int len;
    char tmp;

    i = 0;
    len = 0;
    while (str[len])
        len++;
//    len--;
    while (++i < --len)
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
    //    i++;
    //    len--;
    }
    return (str);
}

// char		*ft_strrev(char *str)
// {
// 	int		i;
// 	int		len;
// 	char	tmp;
//
// 	len = 0;
// 	while (str[len])
// 		len += 1;
// 	i = -1;
// 	while (++i < --len)
// 	{
// 		tmp = str[i];
// 		str[i] = str[len];
// 		str[len] = tmp;
// 	}
// 	return (str);
// }

int main()
{
    char *s = "privet";
    ft_strrev(s);
    printf("%s\n", s);
}
