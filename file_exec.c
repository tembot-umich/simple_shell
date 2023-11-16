#include "shell.h"

/**
 * read_content - Read Content From File
 * @filePath:Filename
 * @argv:Program Name
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
 * @fp:File Descript
 * @argv:Prog Name
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
