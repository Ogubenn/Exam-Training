#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int a = 0;
    int c = (end - start) + 1;
    int *value;

	if (start > end)
		return (ft_rrange(end, start));
    value = (int *)malloc(sizeof(int) * c);
        
    if (value)
    {
        while (a < c)
        {
            value[a] = end;
            end--;
            a++;
        }
    }
    return (value);
}
