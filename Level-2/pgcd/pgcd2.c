#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int a;
    int b;
    a = atoi(av[1]);
    b = atoi(av[2]);
    if (ac == 3)
    {
       if (a > 0 && b > 0)
       {
            while (a != b)
                {
                    if (a > b)
                        a -= b;
                    else
                        b -= a;
                }
                printf("%d",a);
       }
    }
    printf("\n");
    return 0;
}