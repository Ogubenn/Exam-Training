#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int inputDiv;
    int input;
    int div;
    int isWrite;
    int kal;

    isWrite = 0;
    div = 2;

    if (ac == 2)
    {
        input = atoi(av[1]);
        kal = input;
        inputDiv = input / 2;
        //input 12
        // 12 % 2 = 
        while (div <= inputDiv && input >= 1)
        {
            while (input % div == 0)
            {
                input /= div;
                if (isWrite != 0)
                    printf("*");
                isWrite = 1;
                printf("%d", div);
            }
            div++;
        }
        if (!isWrite && input >= 1)
            printf("%d",kal);
    }
    
     printf("\n");

}