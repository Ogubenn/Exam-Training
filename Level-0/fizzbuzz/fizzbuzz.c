#include <unistd.h>

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

void    fizzbuzz(void)
{
    int a = 1;
    
    while (a <= 100)
    {
        if (a % 5 == 0 && a % 3 == 0)
            write(1, "fizzbuzz", 8);
        else if (a % 3 == 0)
            write(1,"fizz", 4);
        else if (a % 5 == 0)
            write (1, "buzz", 4);
        else 
            mal(a);

        a++;
        write (1, "\n", 1);
    }
}
int main(void)
{
	fizzbuzz();
	return 0;
}
