#include "memory.h"

/**
 * env_set - Sets the value of an environment variable.
 * @data: The shell data structure.
 * @index: The name of the environment variable.
 * @v: The value to set for the environment variable.
 * Return: 1 if 'index' or 'v' is NULL.
 * By Kidus Yohannes and Petros Worku.
 */
int env_set(shell_data *data, char *index, char *v)
{
	node_list *knob;
	char *q;
	char *b = NULL;

	if (!index || !v)
		return (0);

	b = malloc(str_length(index) + str_length(v) + 2);
	if (!b)
		return (1);
	str_copy(b, index);
	cat_str(b, "=");
	cat_str(b, v);
	knob = data->envir;
	while (knob)
	{
		q = _starting(knob->str_t, index);
		if (q && *q == '=')
		{
			free(knob->str_t);
			knob->str_t = b;
			data->change_env = 1;
			return (0);
		}
		knob = knob->next;
	}
	insert_endnode(&(data->envir), b, 0);
	free(b);
	data->change_env = 1;
	return (0);
}

/**
 * env_center - Prints the environment variables.
 * @data: The shell data structure.
 * Return: Always returns 0.
 * By Kidus Yohannes and Petros Worku.
 */
int env_center(shell_data *data)
{
	print_string_list(data->envir);
	return (0);
}

/**
 * print_string_list - Prints the strings in a linked list.
 * @lines: The linked list of strings.
 * Return: The number of strings printed.
 * By Kidus Yohannes and Petros Worku.
 */
size_t print_string_list(const node_list *lines)
{
	size_t index = 0;
	
	while (lines)
	{
		_prints(lines->str_t ? lines->str_t : "(nil)");
		_prints("\n");
		lines = lines->next;
		index++;
	}
	return (index);
}

/**
 * history_center - Prints the command history.
 * @data: The shell data structure.
 * Return: Always returns 0.
 * By Kidus Yohannes and Petros Worku.
 */
int history_center(shell_data *data)
{
	string_lprint(data->history);
	return (0);
}

/**
 * string_lprint - Prints the strings in a linked list with line numbers.
 * @s: The linked list of strings.
 * Return: The number of strings printed.
 * By Kidus Yohannes and Petros Worku.
 */
size_t string_lprint(const node_list *s)
{
	size_t m = 0;

	while (s)
	{
		_prints(number_base_con(s->place, 10, 0));
		_printchar(':');
		_printchar(' ');
		_prints(s->str_t ? s->str_t : "(nil)");
		_prints("\n");
		s = s->next;
		m++;
	}
	return (m);
}
