#include "memory.h"

/**
 * error_message - Prints an error message.
 * @data: The shell data structure.
 * @error_t: The error message to print.
 * By Kidus Yohannes and Petros Worku.
 */
void error_message(shell_data *data, char *error_t)
{
	print_str(data->command_name);
	print_str(": ");
	prints_int(data->check_line, STDERR_FILENO);
	print_str(": ");
	print_str(data->argu_val[0]);
	print_str(": ");
	print_str(error_t);
}

/**
 * prints_int - Prints an integer.
 * @numbers: The integer to print.
 * @d_file: The file descriptor to print to.
 * Return: The number of digits printed.
 * By Kidus Yohannes and Petros Worku.
 */
int prints_int(int numbers, int d_file)
{
	int (*__printchar)(char) = _printchar;
	int m, digit_count = 0;
	unsigned int abs, num_set;

	if (d_file == STDERR_FILENO)
		__printchar = print_char;
	if (numbers < 0)
	{
		abs = -numbers;
		__printchar('-');
		digit_count++;
	}
	else
		abs = numbers;
	num_set = abs;
	for (m = 1000000000; m > 1; m /= 10)
	{
		if (abs / m)
		{
			__printchar('0' + num_set / m);
			digit_count++;
		}
		num_set %= m;
	}
	__printchar('0' + num_set);
	digit_count++;

	return (digit_count);
}

