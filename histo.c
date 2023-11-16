#include "shell.h"

/**
 * record - Fill File By User Input
 * @entry: User Input
 * This function appends the user input to
 * a history file for tracking command history
 * Return: -1 Fail 0 Succes
 */
int record(char *entry)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (entry)
	{
		while (entry[len])
			len++;
		w = write(fd, entry, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
 * release_envi - Free Enviroment Variable Array
 * @envi:  Environment variables.
 * This function frees the memory allocated
 * for the array of environment variables.
 * Return: Void
 */
void release_envi(char **envi)
{
	int i;

	for (i = 0; envi[i]; i++)
	{
		free(envi[i]);
	}
}
