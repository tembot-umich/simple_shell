#include "shell.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * The main function initializes the simple shell,
 * reads and processes user input, and executes commands.
 * It also handles built-in commands and the exit
 * condition of the shell.
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *entry, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		read_content(argv[1], argv);
	signal(SIGINT, signal_to_specify);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		entry = get_line();
		if (entry[0] == '\0')
		{
			continue;
		}
		record(entry);
		cmd = _parsecmnd(entry);
		if (_stricmpre(cmd[0], "exit") == 0)
		{
			end_bulletin(cmd, entry, argv, counter);
		}
		else if (see_builtin(cmd) == 0)
		{
			st = manage_builtin(cmd, st);
			release_all(cmd, entry);
			continue;
		}
		else
		{
			st = test_command(cmd, entry, counter, argv);

		}
		release_all(cmd, entry);
	}
	return (statue);
}
/**
 * see_builtin - check builtin
 *
 * @cmnd:command to check
 * This function checks if a given command is a built-in command.
 * Return: 0 Succes -1 Fail
 */
int see_builtin(char **cmnd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmnd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_stricmpre(cmnd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * configure_environment - Creat Array of Enviroment Variable
 * @environm: Array of Enviroment Variable
 * This function initializes an array to store environment
 * variables by duplicating the
 * environment variables from the system's "environ" array.
 * Return: Void
 */
void configure_environment(char **environm)
{
	int i;

	for (i = 0; environ[i]; i++)
		environm[i] = string_duplicate(environ[i]);
	environm[i] = NULL;
}
