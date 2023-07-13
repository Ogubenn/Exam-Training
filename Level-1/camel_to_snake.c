#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int a = 0;
    if (ac == 2)
    {
        while (av[1][a])
        {
            if ((av[1][a] >= 'A' && av[1][a] <= 'Z'))
            {
                av[1][a] += 32;
                write(1, "_", 1);
            } 
            write(1, &av[1][a], 1);
            a++;
        }
    }
    write(1, "\n", 1);
}