#include "shell.h"

/**
 * _putchartr - writes the character c to stdout
 * @p: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errorno is set appropriately.
 */
int _putchartr(char p)
{
	return (write(1, &p, 1));
}
/**
 * _strincopy - copie a string
 * @est:char
 * @srcy:char
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
 * @d:chr
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
 * @stri- chr
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
