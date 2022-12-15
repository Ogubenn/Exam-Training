#include <unistd.h>

int     ft_strcmp(char *s1, char *s2)
{
    int a = 0;
    while (s2[a] == s1[a] && s2[a] && s1[a])
        a++;
    return (s1[a] - s2[a]);

}