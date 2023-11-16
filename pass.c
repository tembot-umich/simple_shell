#include "shell.h"

/**
 * _parsecmnd - Parse Line Of Input
 * @input:User Input To Pasw
 *
 * Return: Array Of strings (token):Simple Shell
 */
char **_parsecmnd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _stritoken(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _stritoken(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
