#include <unistd.h>

size_t ft_strcspn(const char *s, const char *reject)
{
    int a,b;

    a = 0;
    b = 0;
    while (s[a])
    {
        b = 0;
        while(reject[b])
        {
            if (s[a] == reject[b])
                return a;
                b++;
        } 
        a++;
    }
    a = 0;
    while (s[a])
        a++;
    return a;
}
