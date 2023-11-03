#include "memory.h"

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

		check_com_chain(data, buffer, &l, num);
		while (l < num)
		{
			if (command_chain(daya, buffer, &l))
				break;
			l++
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

	buf = buffer;
	return (br);
}


void check_com_chain(shell_data *data,char *b, size_t *q, size_t m, szie_t d)
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
			buffer[m] = 0;
			l = d;
		}
	}

	*q = l;
}

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
int str_length(char *string)
{
	int m = 0;

	if (!string)
		return (0);

	while (*string++)
		m++;
	return (m);
}
