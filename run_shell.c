#include "memory.h"

void init_data(shell_data *data)
{
	data->argu = NULL;
	data->argu_val = NULL;
	data->path = NULL;
	data->argu_count = 0;
}

int is_interactive(shell_data *data)
{
	return (isatty(STDIN_FILENO) && data->readfile <= 2);
}

int run_shell(shell_data *data)
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

	}
	return (1);
}



