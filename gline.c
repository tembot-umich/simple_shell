#include "shell.h"

/**
* get_line - Read The Input By User From Stdin
* This function reads input from the user via standard input.
* It dynamically allocates
* memory to store the input and expands the buffer if needed.
* The input is read until
* a newline character is encountered or the
* end-of-file (EOF) is reached.
*
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
 * This function takes an input string and
 * searches for the '#' character. If found,
 * it truncates the input string at the position
 * of the '#' character, effectively
 * removing everything after it.
 * This is useful for handling comments in the input.
 *
 * @buff: The input string to be modified.
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
