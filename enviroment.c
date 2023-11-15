#include "memory.h"

/**
 * build_environment_variable_list - Build a list of environment variables.
 * @data: Pointer to the shell_data structure.
 * Return: 0 to indicate success.
 * By Kidus Yohannes and Petros Worku.
 */
int build_environment_variable_list(shell_data *data)
{
	node_list *knob = NULL;
	size_t m;

	for (m = 0; environ[m]; m++)
		insert_endnode(&knob, environ[m], 0);
	data->envir = knob;
	return (0);
}

/**
 * load_history - Load command history from a file.
 * @data: Pointer to the shell_data structure.
 * Return: Updated command history count.
 * By Kidus Yohannes and Petros Worku.
 */
int load_history(shell_data *data)
{
	struct stat st;
	char *buffer = NULL, *f_name = filename_history(data);
	int m, ends = 0, count = 0;
	ssize_t file_dis, dlen, size_f = 0;

	if (!f_name)
		return (0);

	file_dis = open(f_name, O_RDONLY);
	free(f_name);
	if (file_dis == -1)
		return (0);
	if (!fstat(file_dis, &st))
		size_f = st.st_size;
	if (size_f < 2)
		return (0);
	buffer = malloc(sizeof(char) * (size_f + 1));
	if (!buffer)
		return (0);
	dlen = read(file_dis, buffer, size_f);
	buffer[size_f] = 0;
	if (dlen <= 0)
		return (free(buffer), 0);
	close(file_dis);
	for  (m = 0; m < size_f; m++)
		if (buffer[m] == '\n')
		{
			buffer[m] = 0;
			add_to_history(data, buffer + ends, count++);
			ends = m + 1;
		}
	if (ends != m)
		add_to_history(data, buffer + ends, count++);
	free(buffer);
	data->count_hist = count;
	while (data->count_hist-- >= HISTORY_MAX)
		index_del(&(data->history), 0);
	history_changenum(data);
	return (data->count_hist);
}
