#include <unistd.h>

int max(int *tab, unsigned int len)
{
	int a;
	int i = 0;
	a = tab[i];
	
	while(i < len)
	{
		if (a <  tab[i])
		{
			a = tab[i];
		}
		i++;
	}
	return a;
}
