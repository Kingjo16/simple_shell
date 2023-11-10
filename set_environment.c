#include "memory.h"

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
	data_>change_env = 1;
	return (0);
}

int env_center(shell_data *data)
{
	print_string_list(data->envir);
	return (0);
}

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
int history_center(shell_data *data)
{
	string_lprint(data->history);
	return (0);
}
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
