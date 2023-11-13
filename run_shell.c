#include "memory.h"

/**
 * init_data - Initializes the shell data structure.
 * @data: The shell data structure to initialize.
 * By Kidus Yohannes and Petros Worku.
 */
void init_data(shell_data *data)
{
	data->argu = NULL;
	data->argu_val = NULL;
	data->path = NULL;
	data->argu_count = 0;
}

/**
 * is_interactive - Checks if the shell is running in interactive mode.
 * @data: The shell data structure.
 * Return: 1 if the shell is running in interactive mode, 0 otherwise.
 * By Kidus Yohannes and Petros Worku.
 */
int is_interactive(shell_data *data)
{
	return (isatty(STDIN_FILENO) && data->readfile <= 2);
}

/**
 * run_shell - Runs the shell.
 * @data: The shell data structure.
 * @arg: The command-line arguments passed to the shell.
 * Return: The value of 'inside' indicating the shell's exit status.
 * By Kidus Yohannes and Petros Worku.
 */
int run_shell(shell_data *data, char **arg)
{
	ssize_t file = 0;
	int inside = 0;

	while (file != -1 && inside != -2)
	{
		init_data(data);
		if (is_interactive(data))
			_prints("$ ");
		print_char(FLUSH);
		file = find_input(data);
		if (file != -1)
		{
		set_command_data(data, arg);
		inside = builtin_cmd(data);
	if (inside == -1)
			return (0);

		}
	}
	return (inside);
}

/**
 * builtin_cmd - Executes built-in commands.
 * @data: The shell data structure.
 * Return: The value of 'fun_built' indicating the success.
 * By Kidus Yohannes and Petros Worku.
 */
int builtin_cmd(shell_data *data)
{
	int m, fun_built = -1;
	function_built builtedfun[] = {
		{"exit", exit_shell},
		{"env", env_center},
		{"help", help_center},
		{"history", history_center},
		{"setenv", set_envir},
		{"unsetenv", unset_envir},
		{"cd", comd_line},
		{"alias", alias_center},
		   {NULL, NULL}
	};

	for (m = 0; builtedfun[m].type; m++)
		if (compar_str(data->argu_val[0], builtedfun[m].type) == 0)
		{
			data->check_line++;
			fun_built = builtedfun[m].bfun(data);
			break;
		}
	return (fun_built);
}
