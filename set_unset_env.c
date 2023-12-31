#include "memory.h"

/**
 * set_envir - Sets the value of an environment variable.
 * @data: The shell data structure.
 * Return: 1 if the environment variable is set successfully.
 * By Kidus Yohanes and Petros Worku.
 */
int set_envir(shell_data *data)
{
	if (data->argu_count != 3)
	{
		print_str("Incorrect number of arguements\n");
		return (1);
	}
	if (env_set(data, data->argu_val[1], data->argu_val[2]))
		return (0);
	return (1);
}

/**
 * unset_envir - Unsets environment variables based on command-line arguments.
 * @data: The shell data structure.
 * Return: Always returns 0.
 * By Kidus Yohanes and Petros Worku.
 */
int unset_envir(shell_data *data)
{
	int m;

	if (data->argu_count == 1)
	{
		print_str("Too few arguements.\n");
		return (1);
	}
	for (m = 1; m <= data->argu_count; m++)
		env_unset(data, data->argu_val[m]);
	return (0);
}

/**
 * env_unset - Unsets an environment variable.
 * @data: The shell data structure.
 * @str: The name of the environment variable to unset.
 * Return: The index of the removed node in environment variable is successful.
 * By Kidus Yohanes and Petros Worku.
 */
int env_unset(shell_data *data, char *str)
{
	char *q;
	size_t m = 0;
	node_list *knob = data->envir;

	if (!knob || !str)
		return (0);

	while (knob)
	{
		q = enter_here(knob->str_t, str);
		if (q && *q == '=')
		{
			data->change_env = index_del(&(data->envir), m);
			m = 0;
			knob = data->envir;
			continue;
		}
		knob = knob->next;
		m++;
	}
	return (data->change_env);
}

/**
 * alias_center - Handles the alias command.
 * @data: The shell data structure.
 * Return: Always returns 0.
 * By Kidus Yohanes and Petros Worku.
 */
int alias_center(shell_data *data)
{
	int m = 0;
	node_list *knob = NULL;
	char *q = NULL;

	if (data->argu_count == 1)
	{
		knob = data->alias_t;
		while (knob)
		{
			_printal(knob);
			knob = knob->next;
		}
		return (0);
	}
	for (m = 1; data->argu_val[m]; m++)

	{
		q = char_loc(data->argu_val[m], '=');
		if (q)
			aliaset(data, data->argu_val[m]);
		else
			_printal(find_node(data->alias_t, data->argu_val[m], '='));
	}
	return (0);
}

