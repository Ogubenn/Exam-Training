#include <unistd.h>

void    last_word(char *str)
{
    int a = 0;
    while (str[a])
        a++;
        a--;
    while (str[a] == '\t' || str[a] == ' ')
        a--;
    while (a>=0)
    {
        if(str[a] == '\t' || str[a] == ' ')
            break;
        a--;
    }
    a++;
    while (str[a] != '\t' && str[a] && str[a] != ' ')
    {
        write(1, &str[a], 1);
        a++;
    }
}
int main(int ac, char **av)
{
    if (ac == 2)
        last_word(av[1]);
    write(1, "\n", 1);
}