#include <unistd.h>

int ft_atoi(char *str)
{
    int a = 0;
    int b = 0;
    while (str[b])
    {
        a = (a * 10) + (str[b] - 48);
        b++;
    }
    return a;
}

void	print_hex(int n)
{
	char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}