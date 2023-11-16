#include "shell.h"

/**
 * manage_builtin - Handle Builtin Command
 * @cmnd: Parsed Command
 * @kl:statue of last Excute
 * This function handles built-in shell commands
 * by comparing the given command
 * with a list of recognized built-in commands.
 * If a match is found, the
 * corresponding built-in function is executed.
 *
 * @cmd: The parsed command and its arguments.
 * @er: The status of the last executed command.
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int manage_builtin(char **cmnd, int kl)
{
	 bul_t bil[] = {
		{"cd", move_directory},
		{"env", env_visualization},
		{"help", show_help},
		{"echo", output_bulletin},
		{"record", record_display},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_stricmpre(cmnd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmnd, kl));
		}
		i++;
	}
	return (-1);
}
/**
 * test_command - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * This function handles the execution of
 * non-built-in shell commands. It forks
 * a new process and attempts to execute the given command.
 * If the command is
 * not found, an error message is printed and the function returns -1.
 *
 * @cmd: The parsed command and its arguments.
 * @input: The original user input.
 * @c: The shell execution count.
 * @argv: The program name.
 *
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int test_command(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (string_compare(*cmd, "./", 2) != 0 && string_compare(*cmd, "/", 1) != 0)
		{
			pathname_cmnd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_specify - Handle ^C
 * @signal:Captured Signal
 * This function is a signal handler specifically for the
 * SIGINT signal (usually
 * generated when the user presses Ctrl+C)
 * It's responsible for printing a new
 * shell prompt after the signal is captured.
 *
 * @signal: The captured signal
 * Return: Void
 */
void signal_to_specify(int signal)
{
	if (signal == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
