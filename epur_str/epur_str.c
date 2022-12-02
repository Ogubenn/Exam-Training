#include <unistd.h>

int main(int ac, char **av)
{
    int a;
    int key;

    a = 0;
    if (ac == 2)
    {
        while (av[1][a] == ' ' || av[1][a] == '\t')
            a++;
        while (av[1][a])
        {
            if (av[1][a] == ' ' || av[1][a] == '\t')
                key = 1;
            if (!(av[1][a] == ' ' || av[1][a] == '\t'))
            {
                if(key)
                    write (1, " ", 1);
                key = 0;
                write (1, &av[1][a], 1);
            }
            a++;
        }
    }
    write (1, "\n", 1);
}