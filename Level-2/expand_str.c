#include <unistd.h>

int word_len(char *str)
{
    int a = 0;
    while (str[a] && str[a] != ' ' && str[a] != '\t')
    ++a;
    return a;
}

void expand(char *str)
{
	int len;
	int first_word = 1;

	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			++str;
		len = word_len(str);
		if (len > 0 && first_word == 0)
			write(1, "   ", 3);
		first_word = 0;
		write(1, str, len);
		str = str + len;
	}
}
int main(int ac, char **av)
{
    if (ac == 2)
        expand(av[1]);
    write(1, "\n", 1);
    return 0;
}