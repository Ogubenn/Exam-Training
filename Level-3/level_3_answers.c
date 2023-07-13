

// ******************** flood_fill ********************

/* ANSWER 

typedef struct s_point { 
	int	x;
	int	y;

}	t_point;


void fill(char **tab, t_point size, t_point cur ,char to_fill ) {

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;
	
	tab[cur.y][cur.x] = 'F'; // fill with f 

	// fill begin to to end

	fill(tab,size, (t_point){cur.x - 1,cur.y},to_fill); // öncesiden
	fill(tab,size, (t_point){cur.x + 1,cur.y},to_fill); // sonrasından
	fill(tab,size, (t_point){cur.x , cur.y - 1},to_fill); // yukarısından
	fill(tab,size, (t_point){cur.x , cur.y + 1}, to_fill); // aşağısından

}


void flood_fill (char **tab,t_point size,t_point begin) {
	fill (tab, size, begin, tab[begin.y][begin.x]);
}

*/


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// ******************** f_prime ********************

/* ANSWER 

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{ 
	int i;
	int number;

	if (ac == 2)
	{ 
		i = 1;
		number = atoi(av[1]);

		if (number == 1)
			printf ("1");
		
		while (number >= ++i)  // i yi 2 leyip devam ettim
		{ 
			if (number % i == 0) // tam bölünürse
			{
				printf("%d",i); // yazıcaz
				if ( number == i) // number böle böle 1 olduğundan i de her işlem sonunca 1 olacağından işlem sonlanır. 
					break;
				printf("*");
				number /= i; // number küüçlcek
				i = 1; // !!! işlemler sonunda i tekrar 1 çevirlcek
			}
		}

	}
}


*/

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// ******************** itoa ********************

/* ANSWER

#include <stdlib.h>

char *ft_itoa(int nbr)
{ 
	int n = nbr;
	int len = 0;

	if (nbr <= 0)
		len++; // negatif işareti için
	
	// n sıfır olana kadar bölüp basmaak sayısını bulduk
	while (n > 0)
	{
		n /= 10;
		len++;
	}

	char *result = (char *)malloc(sizeof(char)*(len + 1));

	if (result == NULL)
	{ 
		return NULL;
	}

	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}

	if (nbr < 0)
	{ 
		result [0] = '-';
		nbr = -nbr; // numarayı pozitefe çek
	}

	while (nbr > 0)
	{ 
		result[--len] = nbr % 10 + '0';   // birler basamağını yazdık
		nbr /= 10; // sayıyı küçülttük
	}
	return result;
}


*/

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// ******************** list_remove_if ********************

/* 

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref , int (*cmp)())
{ 
	if (begin_list == 0 || *begin_list == 0)
		return;
	
	t_list *cur = *begin_list;

	if (cmp(cur -> data,data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list,data_ref,cmp); 
	}

	cur = *begin_list;

	ft_list_remove_if(&cur->next,data_ref,cmp);
}

*/


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// ******************** ft_split ********************

/* ANSWER 

#include <stdlib.h>

int ft_word_len(char *str)
{ 
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;

	return i;
}


char *word_dupe(char *str)
{ 
	int i = 0;
	int len = ft_word_len(str);

	char *word = malloc(sizeof(char) * (len + 1));

	word[len] == '\0';

	while ( i < len )
	{ 
		word[i] = str[i];
		i++;
	}

	return (word);
}


void fill_words (char **array, char *str)
{ 
	int word_index = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;

	while (*str != '\0')
	{ 
		array[word_index] = word_dupe(str);

		++word_index;

		while (*str != '\0' && *str != ' ' && *str != '\t' && str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}

}

int 	count_words(char *str)
{ 
	int num_words;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	
	while (*str != '\0')
	{
		++num_words;

		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}

	return (num_words);
}


char **ft_split(char *str)
{ 
	int 	num_words;
	char	**array;

	num_words = count_words(str);

	array = malloc(sizeof(char *)*(num_words + 1));

	array[num_words] = 0 ;

	fill_words(array,str);

}

*/


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// ******************** ft_list_foreach ********************

/* ANSWER

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{ 
		if (beginlist -> data)
			(*f)(beginlist -> data)
		
		beginlist = begin_list -> next;
	}

}

*/


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

