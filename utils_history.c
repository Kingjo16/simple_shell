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

node_list *insert_endnode(node_list **head, const char *str_t, int place)
{
	node_list *new_n, *ad;

	if (!head)
		return (NULL);

	ad = *head;
	new_n = malloc(sizeof(node_list));
	if (!new_n)
		return (NULL);

	mem_set((void *)new_n, 0, sizeof(node_list));
	new_n->place = place;

	if (str_t)
	{
		new_n->str_t = str_dup(str_t);
		if (!new_n->str_t)
		{
			free(new_n);
			return (NULL);
		}
	}

	if (ad)
	{
		while (ad->next)
			ad = ad->next;
		ad->next = new_n;
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
		knob = knob->next;
	}
	return (data->count_hist = m);
}
int index_del(node_list **hd, unsigned int i)
{
	node_list *knob, *first_n;
	unsigned int m = 0;

	if (!hd || !*hd)
		return (0);

	if(!i)
	{
		knob = *hd;
		*hd = (*hd)->next;
		free(knob->str_t);
		free(knob);
		return (1);
	}
	knob = *hd;
	while (knob)
	{
		if (m == i)
		{
			first_n->next = knob->next;
			free(knob->str_t);
			free(knob);
			return (1);
		}
		m++;
		first_n = knob;
		knob = knob->next;
	}
	return (0);
}


