#include "shell.h"

/**
* get_line - Read The Input By User From Stdin
* Return: Input
*/
char *get_line()
{
int i, buffsize = BUFSIZE, rd;
char c = 0;
char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _reallocate(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	manage_hashtag(buff);
	return (buff);
}

/**
 * manage_hashtag - remove everything after #
 * @buffer: input;
 * Return:void
 */
void manage_hashtag(char *buffer)
{
	int i;

		for (i = 0; buffer[i] != '\0'; i++)
		{
			if (buffer[i] == '#')
			{
			buffer[i] = '\0';
			break;
			}
	}
}
