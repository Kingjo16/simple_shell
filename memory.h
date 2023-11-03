#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZES 1024
#define SUCCESS 0
#define FAILURE 1

#define NORM_COMMAND	0
#define OR_COMMAND	1
#define AND_COMMAND	2
#define CHAIN_COMMAND	3

typedef struct shell_data
{
	char *argu;
	char **argu_val;
	char *path;
	int argu_count;
	int flag_count;
	char **command_buffer;
	int command_type;
	int status;
	int readfile;

} shell_data;

#define INFORMATION_INITIALIZE {0}

#define FLUSH -1

/* error_output.c */

void print_str(char *p_str);
int print_char(char fe);

/* run_shell.c */

void init_data(shell_data *data);
int is_interactive(shell_data *data);
int run_shell(shell_data *data);

/* string_man.c */

char *str_copy(char *destination,char *stringc);
char *str_dup(const char *string);
void _prints(char *string);
int _printchar(char character);

/* alloc.c */

char *mem_set(char *string, char c, unsigned int num);
void free_strings(char **strings);
void *alloc(void *ptr, unsigned int used_s, unsigned int given_s);

/* cahr_exitsearch.c */

char *copy_str(char *destination, char *s_string, int cpy);
char *concat_str(char *destination, char *s_string, int cpy);
char *char_loc(char *dest, char ch);

/* getinput.c */

void handle_signal(__attribute__((unused))int signal_number);
ssize_t into_buf(shell_data *data, char *buffer, size_t *index);
ssize_t read_input_buffer(shell_data *data, char **buffer, size_t *num);
int custom_getline(shell_data *data, char **pointer, size_t *len);
void comment_rm(char *buffer);

/* getinput1.c */

ssize_t find_input(shell_data *data);
void check_com_chain(shell_data *data,char *b, size_t *q, size_t m, size_t d);
int command_chain(shell_data *data, char *buffer, size_t *q);
int str_length(char *string);



#endif
