#include "shell.h"

/**
 * string_copy - Copy Source To Char
 * @est:Destination
 * @srcy:Source
 */
char *string_copy(char *est, char *srcy)
{
int i;

i = 0;
	while (srcy[i])
	{
		est[i] = srcy[i];
		i++;
	}
est[i] = '\0';
return (est);
}

/**
 * _stringconcat - Concat Two String
 * @est:First String
 * @srcy:Second String
 */
char *_stringconcat(char *est, char *srcy)
{
	char *s = est;

	while (*est != '\0')
	{
		est++;
	}

	while (*srcy != '\0')
	{
		*est = *srcy;
		est++;
		srcy++;
	}
	*est = '\0';
	return (s);
}

/**
 * _strchr - Locate Charactere In String
 * @s:String Search In
 * @c:Char To Search For
 */
char *_strchr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);

return (s);
}

/**
 * string_compare - Compare Amount Of Characters between Two Strings.
 * @d1: A String.
 * @d2: A String.
 * @m: Amount Of Characters To Compare.
 */
int string_compare(const char *d1, const char *d2, size_t m)
{
	size_t i;

	if (d1 == NULL)
		return (-1);
	for (i = 0; i < m && d2[i]; i++)
	{
		if (d1[i] != d2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * string_duplicate - Duplicate A String
 * @stri:String
 * Return: Duplicate String Failed Null
 */
char *string_duplicate(char *stri)
{
	size_t len, i;
	char *stri2;

	len = _strilength(stri);
	stri2 = malloc(sizeof(char) * (len + 1));
	if (!stri2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		stri2[i] = stri[i];
	}

	return (stri2);
}
