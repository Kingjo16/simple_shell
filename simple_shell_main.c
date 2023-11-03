#include "memory.h"

int main(int argCount, char **argVal)
{
	shell_data data[] = {0};
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

			return (FAILURE);

		}
		data->readfile = file_dis;
	}
	run_shell(data);
	return (SUCCESS);
}
