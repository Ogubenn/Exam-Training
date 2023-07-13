

// ******************** first_word ********************

/* QUESTION

Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/

/* ANSWER

#include <unistd.h>

int main(int ac,char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while (av[1][i] == ' ' ||  av[1][i] == '\t') // ' ' = 32 ; '\t' == 9
			i++;
		while ( av[1][i] != 32 && av[1][i] != '\t' && av[1][i] != '\0')
		{
			write(1,&av[1][i],1);
			i++;
		}
	}
	write (1,"\n",1);
}

*/

// ********************************************************************

// ******************** fizzbuzz **********************

/* 	QUESTION

Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>

*/

/* ANSWER

#include <unistd.h>

void ft_write_number(int number)
{
	char decimal[10] = "0123456789";

	if (number > 9)
		ft_write_number(number / 10);
	write(1,&decimal[number % 10],1);
}

int main()
{
	int i;

	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1,"fizzbuzz",8);
		else if (i % 3 == 0)
			write(1,"fizz",4);
		else if (i % 5 == 0)
			write(1,"buzz",4);
		else
			ft_write_number(i);
		i++;
		write(1,"\n",1);
	}
}

*/

// ********************************************************************

// ******************** ft_putstr **********************

/* QUESTION

Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);

*/

/* ANSWER

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(1,&str[i],1);
		i++;
	}
}

*/

// ********************************************************************

// ******************** ft_strcpy **********************

/* QUESTION
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

// !!! s2 yi s1 e kopyalıyoruz !!!
/* ANSWER

char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while (s2[i] != '\0')
	{
		s1[i] = s2[i]
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

*/

// *********************************************************************

// ******************** ft_strlen **********************

/* QUESTION

Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);

*/

/* ANSWER

int	ft_strlen(char *str) {

	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

*/

// *********************************************************************

// ******************** ft_swap **********************

/* QUESTION

Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);

*/

/* ANSWER

void	ft_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

*/

// **********************************************************************

// ******************** repeat_alpha **********************

/* QUESTION

Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

*/

/* ANSWER

#include <unistd.h>

int main(int ac,char **av)
{
	int i = 0;
	int repeater;

	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if ( av[1][i] >= 'a' && av[1][i] <= 'z') {
				repeater = av[1][i] - ('a' - 1); // ('a'- 1 == 96)
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z') {
				repeater = av[1][i] - ('A' - 1); // ('A' - 1 == 64)
			}
			while (repeater > 0)
			{
				write(1,&av[1][i],1);
				repeater--;
			}
			write(1,&av[1][i],1); // !!! for non-alpha numeric chars
			i++;
		}
	}
	write (1,"\n",1);
}

*/

// ***********************************************************************

// ******************** rev_print **********************

/* QUESTION

Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$

*/

/* ANSWER

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while (av[1][i] != '\0')
			i++;
		i--; // for pass null terminate
		while (i >= 0)
		{
			write(1, &av[1][i], 1);
			i--;
		}
	}
	write (1,"\n",1);
}

*/

// ************************************************************************

// ******************** rot_13 **********************

/* QUESTION

Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
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
		while (av[1][i])
		{
			if ((av[i][i] >= 'a' && av[1][i] <= 'm') || (av[i][i] >= 'A' && av[1][i] <= 'm'))
				av[1][i] += 13;
			else if((av[i][i] >= 'n' && av[1][i] <= 'z') || (av[i][i] >= 'N' && av[1][i] <= 'Z'))
				av[1][i] -= 13;
			write (1, &av[1][i] ,1);
			i++;
		}
	}
	write (1,"\n",1);

	return (0);
}

*/

// *************************************************************************

// ******************** rot_one **********************

/* QUESTION

Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>

*/

/* ANSWER

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 2)
	{
		while (av[1][i] != '\0')

			if ((av[1][i] >= 'a' && av[1][i] <= 'y') || (av[1][i] >= 'A' && av[1][i] <= 'Y'))
				av[1][i] += 1;

			else if (av[1][i] == 'z' || av[1][i] == 'Z')
				av[1][i] -= 25;

		write(1, &av[1][i], 1);
		i++;
	}

	write(1, "\n", 1);
	return (0);
}

*/

// ************************************************************************

// ******************** search_and_replace **********************

/* QUESTION

Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $

*/

/* ANSWER

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 4 && !av[2][1] && !av[3][1]) // !!! 2. VE 3. argumanlar tek char olmalı
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] == av[2][0])
				av[1][i] = av[3][0];
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

*/

// ************************************************************************

// ******************** ulstr **********************

/* QUESTION

Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$

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
			if (av[1][i] <= 'z' && av[1][i] >= 'a')
				av[1][i] -= 32;
			else if (av[1][i] <= 'Z' && av[1][i] >= 'A')
				av[1][i] += 32;
			write (1,&av[1][i],1);
			i++;
		}
	}
	write(1,"\n",1);
}

*/

// ************************************************************************


// ------------------------ BİTTİ ------------------------ //