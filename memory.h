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

#define ENTERANCE	0

#define LOWERCASE	1
#define UNSIGNED_CON	2

#define NORM_COMMAND	0
#define OR_COMMAND	1
#define AND_COMMAND	2
#define CHAIN_COMMAND	3


typedef struct nodelist
{
	char *str_t;
	int place;
	struct nodelist *next;
} node_list;


typedef struct shell_data
{
	char *argu;
	char **argu_val;
	char *path;
	int argu_count;
	unsigned int check_line;
	int num_error;
	int flag_count;
	char *command_name;
	node_list *envir;
	node_list *history;
	node_list *other_a;
	node_list *alias_t;
	int change_env;
	int status;

	char **command_buffer;
	int command_type;
	int readfile;
	int count_hist;

} shell_data;

#define INFORMATION_INITIALIZE {0}

#define FLUSH -1

typedef struct builtedfun
{
	char *type;
	int (*bfun)(shell_data *);
} function_built;

/* error_output.c */

void print_str(char *p_str);
int print_char(char fe);

/* run_shell.c */

void init_data(shell_data *data);
int is_interactive(shell_data *data);
int run_shell(shell_data *data, char **arg);
int builtin_cmd(shell_data *data);

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

/* information_set.c */

void set_command_data(shell_data *data, char **argVal);
char **split_str(char *s, char *del);
int del_check(char char_delim, char *del);
int string_cmd_replace(char **replaced, char *new);

/* number_converter.c */

char *number_base_con(long int num, int b, int flag);
int string_to_int(char *str);

/* replacer.c */

int cmd_alias_replace(shell_data *data);
node_list *find_node(node_list *knob, char  *fixer, char ch);
char *enter_here(const char *str, const char *prefix);
int cmd_var_replace(shell_data *data);

/* string_cpy.c */

int length_str(char *string);
int compar_str(char *o_ne, char *t_wo);
char *cat_str(char *buf, char *sour);
char *_starting(const char *bags,const char *smaller);

/* alias_here.c */

int _printal(node_list *knob);
int aliaset(shell_data *data, char *var);
int aliasunset(shell_data *data, char *var);
ssize_t index_knob(node_list *enter, node_list *knob);

/* print_error_message.c */

void error_message(shell_data *data, char *error_t);
int prints_int(int numbers, int d_file);

/* set_environment.c */

int env_set(shell_data *data, char *index, char *v);
int env_center(shell_data *data);
size_t print_string_list(const node_list *lines);
int history_center(shell_data *data);
size_t string_lprint(const node_list *s);

/* set_unset_env.c */

int set_envir(shell_data *data);
int unset_envir(shell_data *data);
int env_unset(shell_data *data, char *str);
int alias_center(shell_data *data);

/* shell_builtin.c */

int exit_shell(shell_data *data);
int comd_line(shell_data *data);
char *env_check(shell_data *data, const char *inputs);
int help_center(shell_data *data);

/* utils_history.c */

int add_to_history(shell_data *data, char *command, int line_num);
node_list *insert_endnode(node_list **head, const char *str_t, int place);
int history_changenum(shell_data *data);
int index_del(node_list **hd, unsigned int i);


#endif
