#include <unistd.h>

int main(int ac, char **av)
{
    int a = 0;
    if (ac == 2)
    {
        while (av[1][a])
        {
            if (av[1][a] >= 97 && av[1][a] <= 122)
                av[1][a] = 219 - av[1][a];
            else if (av[1][a] >= 65 && av[1][a] <= 90)
                av[1][a] = 155 - av[1][a];
            write(1, &av[1][a], 1);
            a++;
        }
    }
    write(1, "\n", 1);
}