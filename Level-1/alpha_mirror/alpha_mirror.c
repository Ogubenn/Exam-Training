#include <unistd.h>

int main(int ac, char **av)
{
    int a;

    a = 0;
    if (ac == 2)
    {
        while (av[1][a])
        {
            if (av[1][a] >= 65 && av[1][a] <= 77)
            {
                    av[1][a] = (77 - av[1][a]) + 78;
                    write (1, &av[1][a], 1);
            }
            else if (av[1][a] >= 78 && av[1][a] <= 90)
            {
                    av[1][a] = 65 + (90 - av[1][a]);
                    write (1, &av[1][a], 1);
            }
            else if (av[1][a] >= 97 && av[1][a] <= 109)
            {
                    av[1][a] = (109 - av[1][a]) + 110;
                    write (1, &av[1][a], 1);
            }
            else if (av[1][a] >= 110 && av[1][a] <= 122)
            {
                    av[1][a] = 97 + (122 - av[1][a]);
                    write (1, &av[1][a], 1);
            }
            else{
                write(1, &av[1][a], 1);
            }
            a++;
        }
    }
    write (1, "\n", 1);
}