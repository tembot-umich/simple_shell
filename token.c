#include "shell.h"
/**
 * see_delim - Checks If A Character Match Any Char *
 * @p: Character To Check
 * @stri: String To Check
 * This function checks if a character 'c' matches
 * any character in the string
 * Return: 1 Succes, 0 Failed
 */
unsigned int see_delim(char p, const char *stri)
{
	unsigned int i;

	for (i = 0; stri[i] != '\0'; i++)
	{
		if (p == stri[i])
			return (1);
	}
	return (0);
}

/**
 * _stritoken - Token A String Into Token (strtrok)
 * @stri: String
 * @delim: Delimiter
 * This function tokenizes a string into
 * tokens using the specified delimiter characters
 * Return: Pointer To The Next Token Or NULL
 */
char *_stritoken(char *stri, const char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (stri != NULL)
		nt = stri;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (see_delim(ts[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (see_delim(nt[i], delim) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}
