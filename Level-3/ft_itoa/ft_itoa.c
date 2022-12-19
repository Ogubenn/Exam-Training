#include <stdlib.h>
#include <unistd.h>

char    *ft_itoa(int nbr)
{
    int uzun;
    int tmp;
    char *str;
    int basamak;
    basamak = nbr;

    uzun = 0;
    if (nbr == -2147483648)
        return ("-2147483648");
    str = (char *)malloc(sizeof(char) * 1000);
    if (str == NULL)
        return (NULL);
    if (nbr == 0)
    {
        str[0] = '0';
        return str;
    }
    if (nbr < 0)
    {
        uzun++;
        nbr = nbr * -1;
        str[0] = '-';
    }
    while (basamak)
    {
        basamak /= 10;
        uzun++;
    }
    while (nbr)
    {
        uzun--;
        str[uzun] = (nbr % 10) + '0';
		nbr /= 10;
    }
    return str;
}