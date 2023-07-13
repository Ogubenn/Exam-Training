#include <unistd.h>

int ft_strlen(char *str)
{
    int a = 0;
    while(str[a])
    a++;
    return a;
}