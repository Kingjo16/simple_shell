#include "memory.h"

int _printal(node_list *knob)
{
	char *q = NULL, *m = NULL;

	if (knob)
	{
		q = char_loc(knob->str_t, '=');
		for (m = knob->str_t; m <= q; m++)
			_printchar(*m);
		_printchar('\'');
		_prints(q + 1);
		_prints("'\n");
		return (0);
	}
	return (1);
}
int aliaset(shell_data *data, char *var)
{
	char *q;

	q = char_loc(var, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (aliasunset(data, var));
	
	aliasunset(data, var);
	return (insert_endnode(&(data->alias_t), var , 0) == NULL);

}
int aliasunset(shell_data *data, char *var)
{
	char *q, cap;
	int k;

	q = char_loc(var, '=');
	if (!q)
		return (1);

	cap = *q;
	*q = 0;
	k = index_del(&(data->alias_t),
			index_knob(data->alias_t, find_node(data->alias_t, var, -1)));
	*q = cap;
	return (k);
}
ssize_t index_knob(node_list *enter, node_list *knob)
{
	size_t m = 0;

	while (enter)
	{
		if (enter == knob)
			return (m);
		enter = enter->next;
		m++;
	}
	return (-1);
}



