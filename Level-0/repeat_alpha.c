#include <unistd.h>

int main(int ac, char **av)
{
    int a = 0;
    int x;
    if (ac == 2)
    {
        while (av[1][a])
        {
            x = 1;
            if (av[1][a] >= 'A' && av[1][a] <= 'Z')
                x = av[1][a] - 64;
            if (av[1][a] >= 'a' && av[1][a] <= 'z')
                x = av[1][a] - 96;
            while(x >= 1)
            {
                write(1, &av[1][a], 1);
                x--;
            }
            a++;
        }
    }
    write(1, "\n", 1);
}