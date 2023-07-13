#include <unistd.h>

int ft_atoi(char *str)
{
    int a = 0;
    int result;
    result = 0;
    while (str[a] == ' ' || str[a] == '\t')
        a++;
    while(str[a])
    {
        result = (result * 10) + (str[a] - '0');
        a++;
    }
    return (result);
}
void     hex_number(int a)
{
    char x[] = "0123456789abcdef";
    if (a > 16)
    {
        hex_number(a / 16);
        hex_number(a % 16);
    }
    else
        write(1, &x[a], 1);
}
int main(int ac, char **av)
{
    if (ac == 2)
    {   
        hex_number(ft_atoi(av[1]));
    }
    write(1, "\n", 1);
}