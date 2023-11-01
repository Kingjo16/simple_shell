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

typedef struct shell_data
{
	int readfile;

} shell_data;

#define INFORMATION_INITIALIZE {0}

#define FLUSH -1

/* error_output.c */
void print_str(char *p_str);
int print_char(char fe);



int run_shell(shell_data *data, char **argVal);
#endif
