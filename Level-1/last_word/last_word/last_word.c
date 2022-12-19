#include <unistd.h>


int main(int ac, char **av)
{
    int a = 0;
    if (ac == 2)
    {
    while (av[1][a])
        a++;
        a--;
    while(av[1][a] == ' ' || av[1][a] == '\t' || av[1][a] == '\r')
        a--;
    while (av[1][a] != ' ' && av[1][a] != '\t' && av[1][a])
        a--;
        a++;
    while (av[1][a] != ' ' && av[1][a] != '\t' && av[1][a])
    {
        write(1, &av[1][a], 1);
        a++;
    }
    }
    write(1, "\n", 1);
}