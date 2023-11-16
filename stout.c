#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * This function is responsible for printing a single
 * character to the standard output.
 * It writes the character 'c' to the standard output
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchartr(char p)
{
	return (write(1, &p, 1));
}
/**
 * _strincopy - copie a string
 * @est:char
 * @srcy:char
 * @m:int
 * This function copies up to 'n' characters from
 * the source string 'src' to the destination
 * string 'dest'. If the length of 'src' is
 * less than 'n', the remainder of 'dest' is filled with '\0'.
 *
 * Return:char
 */

char *_strincopy(char *est, char *srcy, int m)
{
int i;

i = 0;
	while (i < m && *(srcy + i))
	{
	*(est + i) = *(srcy + i);
	i++;
	}
	while (i < m)
	{
	*(est + i) = '\0';
	i++;
	}
	return (est);
}

/**
 * _strlength - lenght of string
 * @d:char
 * This function calculates the length of a null-terminated string 's'.
 * Return:int
 */

int _strilength(char *d)
{
	int i;

		for (i = 0; d[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * _strtol - convert to a int
 * @d:string
 * This function converts a string 'd' representing
 * an integer into an actual integer value.
 * Return:int
 */
int _strtol(char *d)
{
int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((d[i] < '0' || d[i] > '9') && (d[i] != '\0'))
	{
		if (d[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((d[j] >= '0') && (d[j] <= '9'))
	{
		n = (n * 10) + x * ((d[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * _puts - print a string
 * @stri:pointer char
 * This function prints a null-terminated
 * string followed by a newline character.
 * return:void
 */
void _puts(char *stri)
{
	int i;

	for (i = 0; stri[i] != '\0'; i++)
	{
		_putchartr(stri[i]);
	}
_putchartr('\n');
return;
}
