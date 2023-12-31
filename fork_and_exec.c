#include "memory.h"
/**
 * node_length - Get the number of nodes in a linked list.
 * @head: Pointer to the head of the linked list.
 * Return: Number of nodes in the linked list.
 * By Kidus Yohannes and Petros Worku.
 */
size_t node_length(const node_list *head)
{
	size_t m = 0;

	while (head)
	{
		head = head->next;
		m++;
	}
	return (m);
}
/**
 * fork_and_exec - Fork a child process and execute a command.
 * @data: Pointer to the shell_data structure.
 * By Kidus Yohannes and Petros Worku.
 */
void fork_and_exec(shell_data *data)
{
	pid_t child_process_id;

	child_process_id = fork();
	if (child_process_id == -1)
	{
		perror("Error:");
		return;
	}
	if (child_process_id == 0)
	{
	if (execve(data->path, data->argu_val, get_environment_variables(data)) == -1)
	{
		data_free(data, 1);
		if (errno == EACCES)
			exit(126);
		exit(1);
	}

	}
	else
	{
		wait(&(data->status));
		if (WIFEXITED(data->status))
		{
			data->status = WEXITSTATUS(data->status);
			if (data->status == 126)
				error_message(data, "Permission denied\n");
		}
	}
}

/**
 * get_environment_variables - Get the environment variables from shell_data.
 * @data: Pointer to the shell_data structure.
 * Return: Pointer to the environment variables as a 'char**'.
 * By Kidus Yohannes and Petros Worku.
 */
char **get_environment_variables(shell_data *data)
{
	if (!data->environ || data->change_env)
	{
		data->environ = string_list(data->envir);
		data->change_env = 0;
	}
	return (data->environ);
}

/**
 * string_list - Create a string array from a linked list of strings.
 * @head: Pointer to the head of the linked list.
 * Return: Pointer to the string array (char**).
 * By Kidus Yohannes and Petros Worku.
 */
char **string_list(node_list *head)
{
	char **str_s, *str_t;
	node_list *knob = head;
	size_t m = node_length(head), l;

	if (!head || !m)
		return (NULL);
	str_s = malloc(sizeof(char *) * (m + 1));
	if (!str_s)
		return (NULL);
	for (m = 0; knob; knob = knob->next, m++)
	{
		str_t = malloc(str_length(knob->str_t) + 1);
		if (!str_t)
		{
			for (l = 0; l < m; l++)
				free(str_s[l]);
			free(str_s);
			return (NULL);
		}
		str_t = str_copy(str_t, knob->str_t);
		str_s[m] = str_t;
	}
	str_s[m] = NULL;
	return (str_s);
}
