#include <stdlib.h>

int *ft_range(int start, int end)
{
    int i = 0;
    int size = abs((end - start) + 1);//abs = mutlak
    int *res;

    res = malloc(sizeof(int) * size);//end - start + 1 kadar yer ayırıyoruz

    if(!res)
        return (NULL);

    if(start < end)
    {
        while(start <= end)
        {
            res[i] = start;
            start++;
            i++;
        }
    }
    else
    {
        while(start >= end)
        {
            res[i] = start;
            start--;
            i++;
        }
    }
    return res;
}
