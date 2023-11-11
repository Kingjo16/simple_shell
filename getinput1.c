#include "memory.h"

/**
 * find_input - Reads input from a buffer and processes it.
 * @data: Pointer to the shell data structure.
 * Return: Returns the length of the processed input or -1 if an error occurs.
 * By Kidus Yohannes and Petros Worku.
 */
ssize_t find_input(shell_data *data)
{
	static char *buffer;
	static size_t m, l, num;
	ssize_t br = 0;
	char **buf = &(data->argu), *p;

	_printchar(FLUSH);
	br = read_input_buffer(data, &buffer, &num);
	if (br == -1)
		return (-1);
	if (num)
	{
		l = m;
		p = buffer + m;

		check_com_chain(data, buffer, &l, m, num);
		while (l < num)
		{
			if (command_chain(data, buffer, &l))
				break;
			l++;
		}

		m = l + 1;
		if (m >= num)
		{
			m = num = 0;
			data->command_type = NORM_COMMAND;
		}

		*buf = p;
		return (str_length(p));
	}
	*buf = buffer;
	return (br);
}

/**
 * check_com_chain - Checks the command chain type and updates the buffer indices.
 * @data: Pointer to the shell data structure.
 * @b: Pointer to the input buffer.
 * @q: Pointer to the current buffer index.
 * @m: Current buffer index.
 * @d: Total number of characters in the buffer.
 * Return: None.
 * By Kidus Yohannes and Petros Worku.
 */
void check_com_chain(shell_data *data,char *b, size_t *q, size_t m, size_t d)
{
	size_t l = *q;

	if (data->command_type == AND_COMMAND)
	{
		if (data->status)
		{
			b[m] = 0;
			l = d;
		}
	}
	if (data->command_type == OR_COMMAND)
	{
		if (!data->status)
		{
			b[m] = 0;
			l = d;
		}
	}

	*q = l;
}

/**
 * command_chain - Checks the command chain type and updates the buffer index.
 * @data: Pointer to the shell data structure.
 * @buffer: Pointer to the input buffer.
 * @q: Pointer to the current buffer index.
 * Return: Returns 1 if the command chain type is updated, 0 otherwise.
 * By Kidus Yohannes and Petros Worku.
 */
int command_chain(shell_data *data, char *buffer, size_t *q)
{
	size_t l = *q;

	if (buffer[l] == '|' && buffer[l + 1] == '|')
	{
		buffer[l] = 0;
		l++;
		data->command_type = OR_COMMAND;
	}
	else if (buffer[l] == '&' && buffer[l + 1] == '&')
	{
		buffer[l] = 0;
		l++;
		data->command_type = AND_COMMAND;
	}

	else if (buffer[l] == ';')
	{
		buffer[l] = 0;
		data->command_type = CHAIN_COMMAND;
	}
	else
		return (0);

	*q = l;
	return (1);
}

/**
 * str_length - Calculates the length of a string.
 * @string: Pointer to the input string.
 * Return: Returns the length of the string.
 * By Kidus Yohannes and Petros Worku.
 */
int str_length(char *string)
{
	int m = 0;

	if (!string)
		return (0);

	while (*string++)
		m++;
	return (m);
}
