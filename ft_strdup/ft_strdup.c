#include <unistd.h>
#include <stdlib.h>

int     ft_strlen(char *str)
{
    int a = 0;
    while (str[a])
    a++;
    return a;
}
char    *ft_strdup(char *src)
{
    int a = 0;
    int b;
    b = ft_strlen(src);
    char *dup;
    dup = (char *) malloc(sizeof(char) * (b + 1));
    if (src == NULL )
        return (NULL);
    while (src[a])
    {
        dup[a] = src[a];
        a++;
    }
    dup[a] = '\0';
    return (dup);
}
