#include "memory.h"
int add_to_history(shell_data *data, char *command, int line_num)
{
	node_list *knob = NULL;

	if (data->history)
		knob = data->history;
	insert_endnode(&knob, command, line_num);

	if (!data->history)
		data->history = knob;
	return (0);
}

node_list *insert_endnode(node_list **head, const char *string, int place)
{
	node_list *new_n, *ad;

	if (!heaed)
		return (NULL);

	ad = *head;
	new_n = malloc(sizeof(node_list));
	if (!new_n)
		return (NULL);

	mem_set((void *)new_n, 0, sizeof(node_list));
	new_n->place = place;

	if (string)
	{
		new_n->string = str_dup(string);
		if (!new_n->string)
		{
			free(new_n);
			return (NULL);
		}
	}

	if (knob)
	{
		while (knob->next)
			knob = knob->next;
		knob->next = new_n;
	}
	else
		*head = new_n;
	return (new_n);
}
int history_changenum(shell_data *data)
{
	int m = 0;
	node_list *knob = data->history;

	while (knob)
	{
		knob->place = m++;
		knob = node->next;
	}
	return (data->count_hist = m);
}
