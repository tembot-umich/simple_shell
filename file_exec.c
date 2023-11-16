#include "shell.h"

/**
 * read_content - Read Command From File
 * @filePath:Filename
 * @argv:Program Name
 * This function reads commands from
 * a file specified by `filename`. It reads each
 * line from the file, parses the command,
 * and executes it if necessary. The function
 * terminates when all lines in the file have been processed.
 *
 * @filename: The name of the file to read commands from.
 * @argv: The program name
 * Return: -1 or  0
 */

void read_content(char *filePath, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filePath, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		respond_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * respond_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * This function takes a line from a file,
 * parses the command, and executes it if necessary.
 * It handles built-in commands, external commands,
 * and also the "exit" command specific
 * to processing a file.
 *
 * @line: The line read from the file.
 * @counter: The error counter (for error reporting).
 * @fp: The file descriptor of the opened file.
 * @argv: The program name.
 * Return : Excute A line void
 */
void respond_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd =_parsecmnd(line);

		if (string_compare(cmd[0], "exit", 4) == 0)
		{
			end_bulletin_for_file(cmd, line, fp);
		}
		else if (see_builtin(cmd) == 0)
		{
			st = manage_builtin(cmd, st);
			free(cmd);
		}
		else
		{
			st = test_command(cmd, line, counter, argv);
			free(cmd);
		}
}

/**
 * end_bulletin_for_file - Exit Shell Case Of File
 * @line: Line From A File
 * @cmnd: Parsed Command
 * @fd:File Descriptor
 * This function handles the "exit" command when
 * processing a line from a file. If no
 * argument is provided, it exits the program
 * with the current error number. If an
 * argument is provided, it attempts to convert
 * it to an integer and exits with that
 * status code. If the argument is not a valid integer,
 * an error message is printed.
 *
 * @cmnd: The parsed command.
 * @line: The line from the file.
 * @fd: The file descriptor of the opened file.
 * Return : Case Of Exit in A File Line
 */
void end_bulletin_for_file(char **cmnd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmnd[1] == NULL)
	{
		free(line);
		free(cmnd);
		fclose(fd);
		exit(errno);
	}
	while (cmnd[1][i])
	{
		if (_isalpha(cmnd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _strtol(cmnd[1]);
	free(line);
	free(cmnd);
	fclose(fd);
	exit(statue);



}
