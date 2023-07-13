#include <unistd.h>
 int check(char *str, char n)
{
    int a = 0;
    while(str[a])
    {
        if (str[a] == n)
            return 1;
        a++;
    }
    return 0;
}
char    *update(char *str, char n , char m)
{
    int a = 0;
    while(str[a])
    {
        if(str[a] == n)
            str[a] = m;
        a++;
    }
    return (str);
}
int  main(int ac, char **av)
{
    int a = 0;
    if (ac == 4)
    {
        if ((av[2][1] == '\0')&& (av[3][1] == '\0' )&& (check(av[1],av[1][0]) == 1))
            update(av[1],av[2][0],av[3][0]);
        while(av[1][a] && av[2][1] == '\0' && av[3][1] == '\0')
        {
            write(1, &av[1][a], 1);
            a++;
        }
    }
    write(1, "\n", 1);
}