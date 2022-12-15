#include <unistd.h>
#include <stdio.h>

void    yazdir(char a)
{
    write(1, &a, 1);
}

void     mal(int a)
{
    if (a <= 9)
        yazdir(a + 48);
    else 
    {
        mal(a / 10);
        mal(a % 10);
    }
}

int main(int ac, char **av)
{
    mal(ac -1);
    write(1, "\n", 1);

}