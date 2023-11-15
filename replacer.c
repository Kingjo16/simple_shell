#include "memory.h"

/**
 * cmd_alias_replace - Replaces an alias in the shell data structure.
 * @data: The shell data structure.
 * Return: 1 if the alias replacement was successful, 0 otherwise.
 * By Kidus Yohannes and Petros Worku.
 */
int cmd_alias_replace(shell_data *data)
{
	node_list *knob;
	char *q;
	int m;

	for (m = 0; m < 10; m++)
	{
		knob = find_node(data->alias_t, data->argu_val[0], '=');
		if (!knob)
			return (0);
		free(data->argu_val[0]);
		q = char_loc(knob->str_t, '=');
		if (!q)
			return (0);
		q = str_dup(q + 1);
		if (!q)
			return (0);
		data->argu_val[0] = q;
	}
	return (1);
}

/**
 * find_node - Finds a node in a linked list.
 * @knob: The head node of the linked list.
 * @fixer: The string to search for in each node.
 * @ch: The character to check in the found node.
 * Return: The node in the linked list that matches the search criteria.
 * By Kidus Yohannes and Petros Worku.
 */
node_list *find_node(node_list *knob, char  *fixer, char ch)
{
	char *q = NULL;

	while (knob)
	{
		q = enter_here(knob->str_t, fixer);

		if (q && ((ch == -1) || (*q == ch)))
			return (knob);
		knob = knob->next;
	}
	return (NULL);
}
/**
 * enter_here - Checks if a prefix exists in a string.
 * @str: The string to search in.
 * @prefix: The prefix to check for.
 * Return: A pointer to the position in 'str' where the prefix ends.
 * By Kidus Yohannes and Petros Worku.
 */
char *enter_here(const char *str, const char *prefix)
{
	while (*prefix)
		if (*prefix++ != *str++)
			return (NULL);
	return ((char *)str);
}

/**
 * cmd_var_replace - Replaces variables in the shell data structure.
 * @data: The shell data structure.
 * Return: Always returns 0.
 * By Kidus Yohannes and Petros Worku.
 */
int cmd_var_replace(shell_data *data)
{
	int m = 0;
	node_list *knob;

	for (m = 0; data->argu_val[m]; m++)
	{
		if (data->argu_val[m][0] != '$' || !data->argu_val[m][1])
			continue;

		if (!compar_str(data->argu_val[m], "$?"))
		{
			string_cmd_replace(&(data->argu_val[m]),
					str_dup(number_base_con(data->status, 10, 0)));
			continue;
		}
		if (!compar_str(data->argu_val[m], "$$"))
		{
			string_cmd_replace(&(data->argu_val[m]),
					str_dup(number_base_con(getpid(), 10, 0)));
			continue;
		}
		knob = find_node(data->envir, &data->argu_val[m][1], '=');
		if (knob)
		{
			string_cmd_replace(&(data->argu_val[m]),
					str_dup(char_loc(knob->str_t, '=') + 1));
			continue;
		}
		string_cmd_replace(&data->argu_val[m], str_dup(""));

	}
	return (0);
}

