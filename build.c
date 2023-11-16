#include "shell.h"

/**
 * end_bulletin - Exit Statue Shell
 * @cmnd: Parsed Command
 * @input: User Input
 * @argv:Program Name
 * @p:Excute Count
 * This function handles the built-in command "exit" for the shell program.
 * It allows the user to exit the shell with a specific exit status
 * or the default status if no exit status is provided.
 * Return: Void (Exit Statue)
 */
void  end_bulletin(char **cmnd, char *input, char **argv, int p)
{
	int statue, i = 0;

	if (cmnd[1] == NULL)
	{
		free(input);
		free(cmnd);
		exit(EXIT_SUCCESS);
	}
	while (cmnd[1][i])
	{
		if (_isalpha(cmnd[1][i++]) != 0)
		{
			_prerror(argv, p, cmnd);
			break;
		}
		else
		{
			statue = _strtol(cmnd[1]);
			free(input);
			free(cmnd);
			exit(statue);
		}
	}
}


/**
 * move_to_directory - Change Dirctorie
 * @cmnd: Parsed Command
 * @ty: Statue Last Command Excuted
 * This function handles the built-in command change
 * directory for the shell program.
 * It allows the user to change the current working directory.
 * Return: 0 Succes 1 Failed
 */
int move_directory(char **cmnd, __attribute__((unused))int ty)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmnd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_stricmpre (cmnd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmnd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * env_visualization - Display Enviroment Variable
 * @cmnd:Parsed Command
 * ty:Statue of Last command Excuted
 * This function handles the built-in command "env"
 * to display environment variables for the shell program.
 * Return:Always 0
 */
int env_visualization(__attribute__((unused)) char **cmnd, __attribute__((unused)) int ty)
{
size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strilength(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * show_help - Displaying Help For Builtin
 * @cmnd:Parsed Command
 * @ty: Statue Of Last Command Excuted
 * This function displays the content of a specified
 * file for the shell program.
 * Return: 0 Succes -1 Fail
 */
int show_help(char **cmnd, __attribute__((unused))int ty)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmnd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchartr('\n');
	return (0);
}
/**
 * output_bulletin - Excute Echo Cases
 * @ty:Statue Of Last Command Excuted
 * @cmnd: Parsed Command
 * This function handles the built-in command "echo" for the shell program.
 * It prints text to the standard output.
 * It also has special handling for printing the exit status,
 * process ID, and PATH environment variable.
 * Return: Always 0 Or Excute Normal Echo
 */
int output_bulletin(char **cmnd, int ty)
{
	char *path;
	unsigned int  pid = getppid();

	if (string_compare(cmnd[1], "$?", 2) == 0)
	{
		output_number_in(ty);
		PRINTER("\n");
	}
	else if (string_compare(cmnd[1], "$$", 2) == 0)
	{
		output_number(pid);
		PRINTER("\n");

	}
	else if (string_compare(cmnd[1], "$PATH", 5) == 0)
	{
		path = get_environment("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (display_echo(cmnd));

	return (1);
}
