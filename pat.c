#include "shell.h"

/**
 * path_cmd -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * This function searches the directories specified
 * in the $PATH environment variable
 * for an executable command.
 * If the command is found, it updates the cmd parameter
 * with the full path of the executable and returns 0.
 * If the command is not found,
 * it returns 1.
 * Return: 1  Failure  0  Success.
 */
int pathname_cmnd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = get_environment("PATH");
	value = _stritoken(path, ":");
	while (value != NULL)
	{
		cmd_path = create(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = string_duplicate(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _stritoken(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * create - Build Command
 * @element: Excutable Command
 * @content: Dirctory Conatining Command
 * This function constructs the full path of the
 * command by combining the directory
 * containing the command and the command itself.
 * It allocates memory for the full path
 * and returns it.
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *create(char *element, char *content)
{
	char *cmd;
	size_t len;

	len = _strilength(content) + _strilength(element) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _stringconcat(cmd, content);
	cmd = _stringconcat(cmd, "/");
	cmd = _stringconcat(cmd, element);

	return (cmd);
}
/**
 * get_environment - Gets The Value Of Enviroment Variable By Name
 * @title: Environment Variable Name
 * This function retrieves the value of an environment
 * variable given its name.
 * It searches through the environment variables array
 * to find the variable with the
 * specified name and returns its value.
 *
 * Return: The Value of the Environment Variable Else NULL.
 */
char *get_environment(char *title)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = _strilength(title);
	for (i = 0 ; environ[i]; i++)
	{
		if (string_compare(title, environ[i], nl) == 0)
		{
			vl = _strilength(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
