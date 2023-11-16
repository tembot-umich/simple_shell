#include "shell.h"

/**
 * record_display - Display History Of User Input Simple Shell
 * @c:Parsed Command
 * @s:Statue Of Last Excute
 * This function displays the history of user inputs
 * stored in the ".simple_shell_history" file.
 * It reads the file line by line and prefixes
 * each line with a counter and then prints it.
 * Return: 0 Succes -1 Fail
 */
int record_display(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);

	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
/**
 * display_echo - Excute Normal Echo
 * @cmnd: Parsed Command
 * This function executes the "echo" command using fork and execve.
 * It creates a child process to execute the
 * command and waits for its completion.
 * Return: 0 Succes -1 Fail
 */
int display_echo(char **cmnd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmnd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
