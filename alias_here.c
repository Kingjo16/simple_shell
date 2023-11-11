#include "memory.h"

/**
 * _printal - Prints all elements of the given array.
 * @knob: Pointer to the node_list structure.
 * Return: Returns 1 if it is Success.
 * By Kidus Yohannes and Petros Worku.
 */
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

/**
 * aliaset - Sets an alias in the shell's data structure.
 * @var: Pointer to the alias string.
 * @data: Pointer to the shell_data structure.
 * Return: Returns 0 on successful.
 * By Kidus Yohannes and Petros Worku.
 */
int aliaset(shell_data *data, char *var)
{
	char *q;

	q = char_loc(var, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (aliasunset(data, var));

	aliasunset(data, var);
	return (insert_endnode(&(data->alias_t), var, 0) == NULL);

}

/**
 * aliasunset - Unsets an alias in the shell's data structure.
 * @var: Pointer to the alias string.
 * @data: Pointer to the shell_data structure.
 * Return: Returns the result of the 'index_del' operation, indicating success (0).
 * By Kidus Yohannes and Petros Worku.
 */
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

/**
 * index_knob - Returns the index of a node in a linked list.
 * @knob: Pointer to the node to find the index of.
 * @enter: Pointer to the starting node of the linked list.
 * Return: Returns the index of 'knob' if found, or -1 if 'knob' is not found.
 * By Kidus Yohannes and Petros Worku.
 */
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
