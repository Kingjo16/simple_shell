#include "memory.h"

/**
 * main - Entry point of the program.
 * @argCount: Number of command-line arguments.
 * @argVal: Command-line arguments.
 * Return: Returns 0 indicating success.
 * By Kidus Yohannes and Petros Worku.
 */
int main(int argCount, char **argVal)
{
	shell_data data[] = { INFORMATION_INITIALIZE };
	int file_dis = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (file_dis)
		: "r" (file_dis));

	if (argCount == 2)
	{
		file_dis = open(argVal[1], O_RDONLY);
		if (file_dis == -1)
		{
			if (errno == EACCES)
				exit(126);

			if (errno == ENOENT)
			{

				print_str(argVal[0]);
				print_str(": 0: Can't open ");
				print_str(argVal[1]);
				print_char('\n');
				print_char(FLUSH);
				exit(127);
			}

			return (EXIT_FAILURE);

		}
		data->readfile = file_dis;
	}
	build_environment_variable_list(data);
	load_history(data);
	run_shell(data, argVal);
	return (EXIT_SUCCESS);
}
