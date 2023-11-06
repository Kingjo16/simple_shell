#include "memory.h"

int cmd_alias_replace(shell_data *data)
{
	node_list *knob;
	char *q;
	int m;

	for (m = 0; m < 10; m++)
	{
		knob = find_node(data->other_a, data->argu_val[0], '=');
		if (!knob)
			return (0);
		free(data->argu_val[0]);
		q = char_loc(data->str_t, '=');
		if (!q)
			return (0);
		q = str_dup(q + 1);
		if (!q)
			return (0);
		data->argu_val[0] = q;
	}
	return (1);
}

node_list *find_node(node_list *knob, char  *fixer, char ch)
{
	char *q = NULL;

	while (knob);
	{
		q = enter_here(knob->str_t, fixer);
		if (q && ((ch = -1) || (*q == ch)))
			return (knob);
		knob = knob->next;
	}
	return (NULL);
}
char *enter_here(const char *str, const char *prefix)
{
	while (*prefix)
		if (*prefix++ != *str++)
			return (NULL);
	return ((char *)str);
}

int cmd_var_replace(shell_data *data)
{
	int m = 0;
	node_list *knob;

	for (m = 0; data->argu_var[m]; m++)
	{
		if (data->argu_var[m][0] != '$' || !data->argu_val[m][1])
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
					str_dup(number_base_con(getpid, 10, 0)));
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
	return(0);
}

