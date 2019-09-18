# include <unistd.h>
# include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main()
{
	int a;
	char *s1 = "Hi!";
	
	a = ft_strlen(s1);
	printf("%d", a);
	return (0);
}
