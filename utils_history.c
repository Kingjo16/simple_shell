#include "memory.h"

/**
 * add_to_history - Add a command to the history linked list.
 * @command: The command to be added to the history.
 * @data: Pointer to the shell_data structure.
 * @line_num: The line number associated with the command.
 * Return: 0 on successful insertion.
 * By Kidus Youhannes and Petros Worku.
 */
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

/**
 * insert_endnode - Insert a new node at the end of a linked list.
 * @head: Pointer to a pointer to the head of the linked list.
 * @str_t: The string to be stored in the new node.
 * @place: The place or position associated with the new node.
 * Return: A pointer to the new node, or NULL if there was an error.
 * By Kidus Youhannes and Petros Worku.
 */
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

/**
 * history_changenum - Update the 'place' value for each node in a linked list
 * @data: Pointer to shell_data structure.
 * Return: The count of nodes in the list.
 * By Kidus Youhannes and Petros Worku.
 */
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

/**
 * index_del - Delete a node at the specified index in a linked list.
 * @hd: Pointer to a pointer to the head of the linked list.
 * @i: The index of the node to be deleted.
 * Return: 1 if the deletion is successful, 0 otherwise.
 * By Kidus Youhannes and Petros Worku.
 */
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


