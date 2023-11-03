#include "memory.h"
void handle_signal(__attribute__((unused))int signal_number)
{
	_prints("\n");
	_prints("$ ");
	_printchar(FLUSH);
}

ssize_t into_buf(shell_data *data, char *buffer, size_t *index)
{
	ssize_t read = 0;

	if (*index)
		return (0);

	r = read(data->readfile, buffer, BUFFER_SIZES);

	if (read >= 0)
		*index = read;

	return (read);
}

ssize_t read_input_buffer(shell_data *data, char **buffer, size_t *num)
{
	ssize_t bytes_read = 0;
	size_t allocate_buf_len = 0;

	if (!*num)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, handle_signal);
	
#if ENTERANCE
		bytes_read = getline(buffer, &allocate_buf_len, stdin);
#else
		bytes_read = custom_getline(data, buffer, &allocate_buf_len);
#endif
		if  (bytes_read > 0)


int custom_getline(shell_data *data, char **pointer, size_t *len)
{
	static char buffer[BUFFER_SIZES];
	static size_t m, num;
	size_t k;
	ssize_t q = 0, s = 0;
	char *p = NULL, *buf_p = NULL, *l;

	p = *pointer;
	if (p && len)

		s = *len;
	if (m == num)
		m = num = 0;

	q = info_buf(data, buffer, &num);

	if (q == -1 || (q == 0 && num == 0))
		return (-1);

	l = char_loc(buffer + m, '\n');
	k = l ? 1 + (unsigned int)(l - buffer) : num;
	buf_p = 
