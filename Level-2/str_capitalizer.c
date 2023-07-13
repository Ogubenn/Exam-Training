#include <unistd.h>
#include <stdio.h>

int issape(char str)
{
    if ((str >= 65 && str <= 90) || (str >= 97 && str <= 122))
        return (1);
    return 0;

}

int main(int ac, char **av)
{
    int b;
    int c;
    int count;

    b = 1;
    c = 0;
    count = 1;
    while ( ac >= 2 && count < ac)
    {
            c = 0;
            while (av[b][c])
            {
                if (issape(av[b][c]))
                {
                    if (av[b][c] >= 65 && av[b][c] <= 90)
                        av[b][c] += 32;
                }
                c++;
            }
            c = 0;
            if (issape(av[b][c]))
                {
                    av[b][c] -= 32;

                }
            while (av[b][c])
            {
                if(av[b][c] == 32 && issape(av[b][c+1]))
                    av[b][c + 1] -= 32;
                write (1, &av[b][c], 1);
                c++;
            }
             write(1, "\n", 1);
        count++;
        b++;
    }
    if(ac == 1){
        write(1, "\n", 1);
    }
}