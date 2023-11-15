#include "memory.h"

/**
 * write_cmd_hist - Write command history to a file.
 * @data: Pointer to the shell_data structure.
 * Return: 1 on success, -1 on failure.
 * By Kidus Yohannes and Petros Worku.
 */
int write_cmd_hist(shell_data *data)
{
	node_list *knob = NULL;
	char *hist_filename = filename_history(data);
	ssize_t file_dis;

	if (!hist_filename)
		return (-1);

	file_dis = open(hist_filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(hist_filename);

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

/**
 * filename_history - Generate the filename for the command history file.
 * @data: Pointer to the shell_data structure.
 * Return: Pointer to the generated filename string.
 * By Kidus Yohannes and Petros Worku.
 */
char *filename_history(shell_data *data)
{
	char *bu, *cmd;

	cmd = env_check(data, "HOME=");
	if (!cmd)
		return (NULL);
bu = malloc(sizeof(char) * (str_length(cmd) + str_length(HISTORY_FILE) + 2));
	if (!bu)
		return (NULL);
	bu[0] = 0;
	str_copy(bu, cmd);
	cat_str(bu, "/");
	cat_str(bu, HISTORY_FILE);
	return (bu);
}

/**
 * write_string_to_fd - Write a string to a file descriptor.
 * @string: Pointer to the string to be written.
 * @file_descriptor: File descriptor of the target file.
 * Return: Total number of bytes written.
 * By Kidus Yohannes and Petros Worku.
 */
int write_string_to_fd(char *string, int file_descriptor)
{
	int bytes_written = 0;

	if (!string)
		return (0);
	while (*string)
	{
		bytes_written += write_char_to_fd(*string++, file_descriptor);
	}
	return (bytes_written);
}

/**
 * write_char_to_fd - Write a character to a file descriptor.
 * @ch: Character to be written.
 * @file_descriptor: File descriptor of the target file.
 * Return: 1 on success.
 */
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
