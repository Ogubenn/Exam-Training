

// ******************** alpha_mirror ********************

/* QUESTION

Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>

*/

/* ANSWER

#include <unistd.h>

int main(int ac,char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = 'A' - av[1][i] + 'Z';
			else if(av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 'a' - av[1][i] + 'z';
			write(1, &av[1][i],1);
			i++;
		}

	}
	write (1,"\n",1);

}

*/

// ********************************************************************

// ******************** camel_to_snake ********************

/* QUESTION

Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$

*/

/* ANSWER

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;

	if (ac = 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] <= 'Z' && av[1][i] >= 'A')
			{
				av[1][i] += 32;
				write(1, "_", 1);
			}
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1,"\n",1);
}

 */

// ********************************************************************

// ******************** do_op ********************

/* QUESTION

Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$

*/

/* ANSWER

#include <stdlib.h>
#include <stdio.h>

int main(int ac,char **av)
{

	if (ac == 4 && !av[2][1]) // !av[2][1] ekstra önlem için yazdım.
	{
		int av_1 = atoi(av[1]);
		int av_3 = atoi(av[3]);

		if (av[2][0] == '+')
			printf("%d",av_1+av_3);
		else if (av[2][0] == '-')
			printf("%d",av_1-av_3);
		else if (av[2][0] == '*')
			printf("%d",av_1*av_3);
		else if (av[2][0] == '/')
			printf("%d",av_1/av_3);
		else if(av[2][0] == '%')
			printf("%d",av_1%av_3);
	}
	printf("\n");
}

*/

// ********************************************************************

// ******************** atoi ********************

/* QUESTION

Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);

*/

/* ANSWER

int	ft_atoi(const char *str)

{
	int i = 0;
	int result = 0;
	int sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

*/

// ********************************************************************

// ******************** strcmp ********************

/* QUESTION

Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);

*/

// !!! UNUTMA S1 - S2
/* ANSWER

int    ft_strcmp(char *s1, char *s2) {

	int i;

	i = 0;
	while ( s1[i] == s2[i] && s1[i] == '\0' && s2[i] == '\0')
		i++;
	return (s1[i] - s2[i]);
}

*/

// ********************************************************************

// ******************** strcspn ********************

/* QUESTION

Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

strcspn nedir= Program strcspn() fonksiyonu ile bir karakter dizisi
içindeki karakterlerin herhangi birinin diğer karakter dizisi içinde
bulunduğu ilk yerin indeksini hesaplayarak elde ettiği sonucu ekrana
yazar.

*/

/* ANSWER

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);  // !!! j yi değil i yi return etcez.
			j++;
		}
		i++;
	}
	return (i);
}

*/

// ********************************************************************

// ******************** strdup ********************

/* QUESTION

Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

*/

/* ANSWER

#include <stdlib.h>

int ft_strlen(char *str) {

	int i = 0;

	while (str[i] != '\0')
		i++;
	return i;
}

char    *ft_strdup(char *src) {

	int len = ft_strlen(src);
	char *src_copy = malloc(sizeof(char)*len + 1);
	int i = 0;

	if (src_copy == NULL)
		return (NULL);

	while (src[i] != '\0')
	{
		src_copy[i] = src[i];
		i++;
	}
	src_copy[i] = '\0';
	return (src_copy);
}

*/

// ********************************************************************

// ******************** strpbrk ********************

/* QUESTION

Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

strpbrk() fonksiyonu
Str2 parametresi ile gösterilen karakter dizisinde yer alan karakterlerden
herhangi birinin str1 parametresi ile gösterilen karakter dizisi içinde
bulunduğu yerin bellek adresini geri döndürür. Eğer aranan karakterlerden
hiç biri bulunamazsa NULL bir işaretçi geri döndürür.

*/

/* ANSWER

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	int j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[j]);  // tek fark bu strcspn den
			j++;
		}
		i++;
	}

	return (0);
}

*/

// ********************************************************************

// ******************** strrev ********************

/* QUESTION

Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*/

/* ANSWER

char    *ft_strrev(char *str)
{
	int i = 0;
	int length = 0;
	char temporary;

	while (str[length] != '\0')
		length++;

	while (i < length / 2) // 0 , 1 , 2(not)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i]; // 0 = 3 // 1 = 2
		str[length - 1 - i] = temporary; // 3 = 0 // 2 = 1
		i++;
	}
	return (str);
}


// samet // t...s // te.as // m olduğu yerde duruyor (5 elemanlı)

// abla  // a..a // al.a// alba

*/

// ********************************************************************

// ******************** strspn ********************

/* QUESTION

strspn nedir;

size_t strspn(const char *str1, const char *str2);

Str1 parametresi ile gösterilen karakter dizisinde sadece str2 parametresi
ile gösterilen karakter dizisinde yer alan karakterlerin bulunduğu ilk
kısmın uzunluğunu geri döndürür. Arama işlemine sonlandırıcı boş
karakterler ('\0') dahil edilmez.

Str1 veya str2 parametresi boş bir karakterle sonlandırılmış bir karakter
dizisini gösteren bir işaretçi değilse, sonuç belirsiz olabilir.

---------------------------------------------------------------
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

*/

/* ANSWER

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strspn(const char *str1, const char *str2)
{
	size_t	i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i])
	{
		if (ft_strchr(str2, str1[i]))
			i++;
		else
			return (i);
	}
	return (i);
}

*/

// ********************************************************************

// ******************** inter ********************

/* QUESTION

	Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$

*/

/* ANSWER

// ÖZET: av_1 de öncesinde  matchi olmayan bir karakter varsa ve bu
// karekter in av_2 de matchi varsa yazılır .

#include <unistd.h>

// tekrar eden karekter varmı av[1] de
int	check_one(char* str, char c, int current_index)
{
	int	i;

	i = 0;
	while (str[i] && (i < current_index))
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

// av[2] de av[1] deki char var mı
int	check_two(char* str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char* argv[])
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (check_one(argv[1], argv[1][i], i))
			{
				if(check_two(argv[2], argv[1][i]))
					write(1, &argv[1][i], 1);
			}
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}

*/

// ********************************************************************

// ******************** is_power_of_2 ********************

/* QUESTION

Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);

*/

/* ANSWER

int is_power_of_2(unsigned int n)
{
	if (n == 0)
		return 0;
	while (n % 2 == 0)
	{
		n /= 2;
	}
	if (n == 1)
		return 1;
	else
		return 0;
}

//**************************

// açıklama;
int main()
{
	printf("%d\n", is_power_of_2(20));
	// 20 = 2 * 2 * 5
	// ( 5 bozuyor bunada /2 ile 20 / 2 = 10 , 10/2 = 5 diyerek ulaşır .)
	printf("%d", is_power_of_2(2));
	// 2 ye böle böle n = 1 çarpanına ulaşırız 1%2 0 olmaz
	// ve çıkarız return 1 yazdırırız.
}

// alternatife;
int	    is_power_of_2(unsigned int n) {

	int number = 1;

	while (number <= n)
	{
		if (number == n)
			return 1;
		number = number * 2 ;
	}
	return 0;
}

*/

// ********************************************************************

// ******************** last_word ******************** ! ALTERNATİF ÇÖZÜMÜ TEK MAIN DE YAZ

/* QUESTION

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/

/* ANSWER

// ********************************************

// yazdırılabilir arağı baz alarak algoritma;

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		while (argv[1][i] <= 32)
			i--;
		while (argv[1][i] > 32)
			i--;
		i++;
		while (argv[1][i] > 32)
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

// ********************************************

// tab ve space i baz alan çözüm ;

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_last_word(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i -= 1;
	while (s[i] == ' ' || s[i] == '\t')
		i--;
	while ((s[i] != ' ' && s[i] != '\t') && i >= 0)
		i--;
	i += 1;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_last_word(av[1]);
	ft_putchar('\n');
	return (0);
}

*/

// ********************************************************************

// ******************** max ********************

/* QUESTION

Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

*/

/* ANSWER

int		max(int* tab, unsigned int len)
{
	int i = 0;
	int result = tab[i];

	if (len == 0)
		return 0;

	while (i < len)
	{
		if (result < tab[i])
		{
			result = tab[i];
		}
		i++;
	}
}

*/

// ********************************************************************

// ******************** print_bits ********************

/* QUESTION

Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"

*/

/* ANSWER

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char 	bit;

	while (i >= 0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

int main() {
	print_bits('A');
}

*/

// ********************************************************************

// ******************** reverse_bits ********************

/* QUESTION

Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100

*/

/* 	ANSWER

unsigned char reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

*/

// ******************** swap_bits ********************

/* QUESTION

Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
	 \ /
	 / \
 0001 | 0100

*/

/* ANSWER

unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) || (octet << 4));
}

*/

// ********************************************************************

// ******************** snake_to_camel ********************

/* QUESTION

Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$

*/

/* ANSWER

#include <unistd.h>

int main(int ac,char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while(av[1][i] != '\0')
		{
			if (av[1][i] == '_') {
				i++;
				av[1][i] -= 32;
			}
			write(1,&av[1][i],1);
			i++;
		}
	}
	write(1,"\n",1);
}

// dipnot: soruda newline ve ac ile ilgili bir anlatım yok ama
// ek olarak eklendi.

*/

// ********************************************************************

// ******************** union ********************

/* QUESTION

Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

*/

/* ANSWER

// ÖZET : iki stringi(av_1 & av_2) birleştir matchi(öncesinde) olmayanları yaz

#include <unistd.h>

int check(char c, char *str, int index)
{
	int i = 0;

	while (i < index)
	{
		if (str[i] == c)
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	int k = 0;

	if (ac == 3)
	{
		while (av[1][i])
			i++;

		// av_1 ve av_2 uc uca eklendi (yeni string)
		while (av[2][j])
		{
			av[1][i] = av[2][j];
			i++;
			j++;
		}

		i--; // passed null terminate

		// yeni stringde dolaşma
		while (k <= i)
		{
			if (check(av[1][k],av[1],k) == 1)
				write (1 , &av[1][k],1);
			k++;
		}
	}
	write(1,"\n",1);
}

*/

// ********************************************************************

// ******************** wdmatch ********************

/* QUESTION

Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$

*/

/* ANSWER

// özet : av_1 in her elemanının av_2 de matchi varsa check edip yazıyoruz.
// dipnot : av_1 elemanları av_2 de ordered şekilde bulunmalı.

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int k = 0;

	if (argc == 3)
	{

		while(argv[2][j] != '\0' && argv[1][j] != '\0')
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}

		// av_1 i bitiremediysek yani daha hala av_2 de match olamayan
		// char lar varsa (tüm av yi döndüğümüzde bile) bu if e girmiyecek.

		if (argv[1][i] == '\0')  // !argv[1][i] şeklinde de yazılabilir.
		{
			while(argv[1][k])
			{
				write(1, &argv[1][k], 1);
				k++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

// dipnot: av[1][i] != '\0' => 1.arguman da tüm matchleri bulduğunda av2 de ,
// , av2 içindde boş yere dönememesi için.

*/

// ********************************************************************


// ------------------------ BİTTİ ------------------------ //