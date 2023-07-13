#include <unistd.h>

int main(int ac, char **av)
{
    int a = 0;
    int b = 0;
    if (ac == 2)
    {
        while (av[1][a])
        {
            if ((av[1][a] == ' ') && (av[1][a + 1] >= 33 && av[1][a+ 1] <= 126))
                b = a + 1;
            a++;
        }
        while (av[1][b] >= 33 && av[1][b] <= 126)
        {
            write(1, &av[1][b], 1);
            b++;
        }

    } 
    write(1, "\n", 1);
}