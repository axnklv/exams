# include <unistd.h>

int main(int ac, char **av)
{
	write(1, "z\n", 2);
	return (0);
}
