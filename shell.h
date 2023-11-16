#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strilength(c)))

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

char *_stritoken(char *stri, const char *toke);
unsigned int see_delim(char p, const char *stri);
char *_strincopy(char *est, char *srcy, int m);
int _strilength(char *d);
int _putchartr(char p);
int _strtol(char *d);
void _puts(char *stri);
int _stricmpre(char *d1, char *d2);
int _isalpha(int p);
void array_reverse(char *array, int length);
int int_length(int digit);
char *_itoa(unsigned int m);
char *_stringconcat(char *est, char *srcy);
char *string_copy(char *est, char *srcy);
char *string_char(char *d, char p);
int string_compare(const char *d1, const char *d2, size_t m);
char *string_duplicate(char *stri);

void release_envi(char **envi);
void *occupy_array(void *z, int ty, unsigned int width);
char *mem_duplicate(char *est, char *srcy, unsigned int m);
void *_calloc(unsigned int size);
void *_reallocate(void *pointer, unsigned int small_size, unsigned int big_size);
void release_all(char **entry, char *line);

void prompt(void);
void signal_to_specify(int signal);
char *get_line(void);

int pathname_cmnd(char **text);
char *get_environment(char *title);
char **_parsecmnd(char *cmnd);
int manage_builtin(char **cmnd, int kl);
void read_content(char *filePath, char **argv);
char *create(char *element, char *content);
int see_builtin(char **cmnd);
void configure_environment(char **environm);
int test_command(char **units, char *line, int amount, char **argv);
void respond_file(char *line, int counter, FILE *fd, char **argv);
void end_bulletin_for_file(char **cmnd, char *line, FILE *fd);

void manage_hashtag(char *buffer);
int record(char *entry);
int record_display(char **cmd, int ty);
int env_visualization(char **cmnd, int ty);
int move_directory(char **cmnd, int ty);
int show_help(char **cmnd, int ty);
int output_bulletin(char **cmnd, int ty);
void  end_bulletin(char **cmnd, char *input, char **argv, int p);
int display_echo(char **cmnd);

void output_number(unsigned int m);
void output_number_in(int m);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
