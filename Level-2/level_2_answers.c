

// ******************** ft_list_size ********************

/* QUESTION

Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :

typedef struct    s_list
{
	struct s_list *next;
	void          *data;
}                 t_list;

*/

/* ANSWER

// ayrı dosyada ft_list.h olarak tanımlancak;

typedef struct  s_list
{
	struct s_list	*next;
	void			*data;

} t_list;

// #include "ft_list.h"

int	ft_list_size(t_list *begin_list) {

	if (begin_list == 0)
		return 0;
	else
		return (1 + ft_list_size(begin_list -> next));
}

*/

// ********************************************************************

// ******************** ft_range ********************

/* QUESTION

Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

*/

/* ANSWER

#include <stdlib.h>

int *ft_range (int start , int end)
{
	int i = 0;
	int size = abs((end - start)) + 1;
	int *res;

	res = malloc(sizeof(int)*size);

	if (!res)
		return (NULL);

	if (start < end)
	{
		while (start <= end)
		{
			res[i] = start;
			start++;
			i++;
		}
	}
	else {

		while (start >= end)
		{
			res[i] = start;
			start--;
			i++;
		}

	}

	return (res);

}
 */

// ********************************************************************

// ******************** paramsum ********************

/* QUESTION

Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>

*/

/* ANSWER

#include <unistd.h>

void ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	char c = (n%10) + '0';
	write(1,&c,1);
}

int main(int ac , char **av)
{
	(void) av; // av yi kullanmadığımız için

	ft_putnbr(ac - 1);
	write(1,"\n",1);
}

*/

// ********************************************************************

// ******************** lcm ********************

/* QUESTION

Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);

*/

/* ANSWER

// 1.yol

 unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;

	if (a == 0 || b == 0)
		return (0);

	if (a > b)
		n = a;

	else
		n = b;

	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

// 2.yol (daha mantıklı ve verimli)

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;

	lcm = (a < b) ? b : a;
	// büyük olanı seçip daha az adımda en küçük ortak kata erişmek için.

	while (a > 0 && b > 0)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm += (a < b) ? b : a;
	}

	return (0);
}

*/

// ********************************************************************

// ******************** pgcd ********************

/* QUESTION

Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$

*/

/* ANSWER

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int n = a;
	// n = a < b ? a : b denilebilir ;
	// en büyük ortak böleni bulmak için küçük olandan başlayarak
	// azaltmak daha az adımda buldurur çünkü.

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return;
		}
		n--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}

*/

// ********************************************************************

// ******************** tab_mult ********************

/* QUESTION

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>

*/

/* ANSWER

// grademe ile benzer

#include <unistd.h>

int atoi(char *av_1)
{
	int i = 0;
	int result = 0;

	while (av_1[i] != '\0')
	{
		if (av_1[i] <= '9' && av_1[i] >= '0')
			result = result * 10 + (av_1[i] - '0');
		i++;
	}

	return result;
}

void ft_putnbr(int n)
{

	if (n >= 10)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int i = 1;
	int multiplier = 1;

	if (ac != 2)
		write(1, "\n", 1);

	if (ac == 2)
	{
		int av_1 = atoi(av[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(av_1);
			write(1, " = ", 3);
			ft_putnbr(av_1 * i);
			write(1, "\n", 1);
			i++;
		}
	}
	// write(1, "\n", 1); // sakın bu şekilde yazma son satır bozuluyor.
}

*/

// ********************************************************************

// ******************** print_hex ********************

/* QUESTION

Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

*/

/* ANSWER

// benim çözüm (grademe ile benzer)

#include <unistd.h>

void convert_hex(int num)
{
	char *base_16 = "0123456789abcdef";

	if (num > 16)
		convert_hex(num / 16);
	char c = base_16[num % 16];
	write (1, &c,1);
}

int ft_atoi(char *av)
{
	int i = 0;
	int result = 0;

	while (av[i] != '\0')
	{
		if (av[i] <= '9' && av[i] >= '0')
			result = result * 10 + (av[i] - '0');
		i++;
	}
	return (result);
}

int main(int ac,char **av)
{
	int i = 0;

	if (ac == 2) {

		int av_1 = ft_atoi(av[1]);
		convert_hex(av_1);
	}

	write (1, "\n",1);
}

*/

// ******************** hidenp ********************

// ********************************************************************

// ******************** epur_str ********************

/* QUESTION

Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

*/

/* ANSWER

// özet : verile n argümanı tek boşluk atarak yazma .

#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i = 0;
	int flg = 0; // başlangıçda değerler ver yada if den önce!!!

	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flg = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flg)
					write(1, " ", 1);
				flg = 0;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

*/

// ********************************************************************

// ******************** epur_str ********************

/* QUESTION

Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>

*/

/* ANSWER

// özet : verilen argumanı 3 boşluklu şekilde yazma

#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	int flag = 0;

	if (ac == 2) {

		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;

		while (av[1][i]) {

			if (av[1][i] == '\t' || av[1][i] == ' ')
				flag = 1;

			if (!(av[1][i] == '\t' || av[1][i] == ' '))
			{
				if (flag)
					write(1,"   ",3);
				flag = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}

	}
	write (1, "\n", 1);
}

*/

// ********************************************************************

// ******************** ft_strcapitalizer ******************** KENDİN YAZ

/* QUESTION

Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
	 Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>

 */

/* ANSWER

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 2)
	{
		// ilk gelen kelimenin ilk harfi ve tek harfli kelime için;
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
			av[1][i] -= 32;

		write (1, &av[1][i],1);

		while (av[1][i])
		{
			// İlk harfden sonra gelenleri küçültmek içn
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] += 32;

			// boşluk sonrası başlayan kelimenin ilk harfi için
			if ((av[1][i] >= 'a' && av[1][i] <= 'z') &&
			(av[1][i-1]) == ' ' || av[1][i - 1] == '\t')
				av[1][i] -= 32;

			write (1, &av[1][i],1);

			i++;
		}
	}
	write (1,"\n",1);
	return (0);
}

*/

// ********************************************************************

// ******************** rstr_capitalizer ********************

/* QUESTION 

Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>

*/

/* ANSWER  

// özet: farkı son karekteri büyütmek diğerlerini küçültmek
// aynı şekilde ilk len kelime tek harfli ise onu büyütmek.

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] += 32;
			if ((av[1][i] >= 'a' && av[1][i] <= 'z') &&
				(av[1][i + 1] == ' ' || av[1][i + 1] == '\t' || av[1][i + 1] == '\0'))
				av[1][i] -= 32;

			write(1, &av[1][i], 1);

			i++;
		}
	}
	write(1, "\n", 1);
}

*/

// ******************** hidenp ********************

/* QUESTION

Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>

*/

/* ANSWER

// özet:  wd_matchin 1, 0 versiyonu

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;

	if (argc == 3)
	{
		while(argv[2][j] != '\0' && argv[1][i] != '\0')
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}

		if (argv[1][i] == '\0')
			write(1,"1",1);

		else
			write(1,"0",1);

	}
	write(1, "\n", 1);
	return (0);
}

*/

// ********************************************************************

// ******************** add_prime_sum ********************

/* QUESTION

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/

/* ANSWER

// ÖZET = 5 => 2 , 3 , 5 => 2 + 3 + 5 = 10

#include <unistd.h>

// short atoi

int		ft_atoi(char *str)
{
	int n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0'; // in-one-line => n = n * 10 + (*str - '0') ;
		++str;
	}
	return (n);
}

// int to char

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int		is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int		add_prime_sum(int n)
{
	int sum = 0;
	int i = 2;

	while (i <= n)
	{
		if (is_prime(i) == 1)
			sum += i;
		++i;
	}
	return (sum);
}

int		main(int argc, char **argv)
{
	int n;

	if (argc == 2 && (n = ft_atoi(argv[1])))
		ft_putnbr(add_prime_sum(n));
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}

*/

// ********************************************************************

// ********************************************************************

// ******************** atoi_base ********************

/* ANSWER

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A')); // daha net (c - 'A') + 'a'
	return (c);
}

int getdigit(char c, int digit_in_base)
{
	int max_digit; // tabanın toplam kaç digit(basamak)

	// find base 
	if(digit_in_base <= 10) // bence < 10 olmalı en yüksek taban 9 olması için
		max_digit = digit_in_base + '0'; // 0123456789 
	else 
		max_digit = digit_in_base - 10 + 'a'; // abcdef
	
	// find digit element as max_digit base
	if (c >= '0' && c <= '9' && c <= max_digit) 
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else 
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{ 
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{ 
		sign = -1;
	}

	while ((digit = get_digit(to_lower(*str),str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		++str;
	}
	return (result);
}

*/




// ********************************************************************


// ********************************************************************

