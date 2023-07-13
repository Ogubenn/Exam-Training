#include <unistd.h>

int is_power_of_2(unsigned int n)
{
    int a = 1;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    while(a <= n / 2)
    {
        a = a * 2;
        if (n == a)
            return 1;
    }
    return 0;
}