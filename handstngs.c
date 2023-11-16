#include "shell.h"

/**
 * _stricmpre - Compare Two String
 * @d1:String 1
 * @d2:String 2
 * This function compares two strings character by character.
 * It returns 0 if
 * the strings are identical and a non-zero value
 * indicating the difference if
 * they are not identical.
 * Return: 0 If Identical Otherwise How Much Diffrent
 */
int _stricmpre(char *d1, char *d2)
{
int cmp = 0, i, len1, len2;
len1 = _strilength(d1);
len2 = _strilength(d2);

	if (d1 == NULL || d2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; d1[i]; i++)
	{
		if (d1[i] != d2[i])
		{
			cmp = d1[i] - d2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * _isalpha - Check if Alphabtic
 *@p: Characteric
 * This function checks if the given character is alphabetic
 * Return: 1 If True 0 If Not
 */
int _isalpha(int p)
{
if (((p >= 97) && (p<= 122)) || ((p >= 65) && (p <= 90)))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * This function converts an integer to its string representation
 * Return: Char Pointer
 */
char *_itoa(unsigned int m)
{
	int len = 0, i = 0;
	char *s;

	len = int_length(m);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (m / 10)
	{
		s[i] = (m % 10) + '0';
		m /= 10;
		i++;
	}
	s[i] = (m % 10) + '0';
	array_reverse(s, len);
	s[i + 1] = '\0';
	return (s);
}
/**
 *  array_reverse - Reverse Array
 * @array:Array To Reverse
 * @length:Length Of Array
 * This function calculates the number of digits in the given integer.
 *
 * Return: Void(Reverse Array)
 */
void array_reverse(char *array, int length)
{
	int i;
	char tmp;

	for (i = 0; i < (length / 2); i++)
	{
		tmp = array[i];
		array[i] = array[(length - 1) - i];
		array[(length - 1) - i] = tmp;
	}
}
/**
 * int_length - Determine Length Of Int
 * @digit: Given Int
 * Return: Length Of Int
 */
int int_length(int digit)
{
	int length = 0;

	while (digit != 0)
	{
		length++;
		digit /= 10;
	}
	return (length);
}
