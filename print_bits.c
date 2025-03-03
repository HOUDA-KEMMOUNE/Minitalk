#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	int	shift;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << i;
		bit = shift & octet;
		if (bit == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i--;
	}
}

int	main()
{
	char	*str;
	int		i;

	str = "mar7baabiik";
	i = 0;
	while (str[i])
	{
		print_bits(str[i]);
        write(1, " => ", 4);
        write(1, &str[i], 1);
        write(1, "\n", 1);
		i++;
	}
}
