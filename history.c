#include "memory.h"

int write_cmd_hist(shell_data *data)
{
	node_list *knob = NULL;
	char *hist_filename = filename_history(data);
	ssize_t file_dis;

	if (!hist_filename)
		return (-1);

	file_dis = open(hist_filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(hsit_filename);

	if (file_dis == -1)
		return (-1);
	for (knob = data->history; knob; knob = knob->next)
	{
		write_string_to_fd(knob->str_t, file_dis);
		write_char_to_fd('\n', file_dis);
	}
	write_char_to_fd(FLUSH, file_dis);
	close(file_dis);
	return (1);

}

char *filename_history(shell_data *data)
{
	char *buffer, *cmd;

	cmd = env_check(data, "HOME=");
	if (!cmd)
		return (NULL);
	buffer[0] = 0;
	str_copy(buffer, cmd);
	cat_str(buffer, "/");
	cat_str(buf, HIST_FILE);
	return (buffer);
}
int write_string_to_fd(char *string, int file_descriptor)
{
	int bytes_written = 0;

	if (!string)
		return 0;
	while (*string)
	{
		bytes_written += write_char_to_fd(*string++, file_descriptor);
	}
	return bytes_written;
}
int write_char_to_fd(char ch, int file_descriptor)
{
	static int buffer_index;
	static char write_buffer[MAX_BUFFER_SIZE];

	if (ch == FLUSH || buffer_index >= MAX_BUFFER_SIZE)
	{
		write(file_descriptor, write_buffer, buffer_index);
		buffer_index = 0;
	}
	if (ch != FLUSH)
		write_buffer[buffer_index++] = ch;
	return (1);
}
