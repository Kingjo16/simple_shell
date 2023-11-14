#include "memory.h"

void find_executable(shell_data *data)
{
	char *path = NULL;
	int m, l;

	data->path = data->argu_val[0];
	if (data->flag_count == 1)
	{
		data->check_line++;
		data->flag_count = 0;
	}
	for (m=0, l = 0; data->argu[m]; m++)
		if (!del_check(data->argu[m], " \t\n"))
			l++;
	if (!l)
		return;
	
	path = path_finder(data, env_check(data, "PATH="), data->argu_val[0]);
       if (path_var)
       {
	       data->path = path;
	       fork_and_exec(data);
       }
       else
       {
	       if ((is_interactive(data) || env_check(data, "PATH=")
		|| data->argu_val[0][0] == '/') && cmd_check(data, data->argu_val[0]))
		       fork_and_exec(data);
	       else if (*(data->argu) != '\n')
	       {
		       data->status = 127;
		       error_message(data, "not found\n");
	       }
       }
}

/**
 * path_finder - Find the executable file in the specified paths.
 * @data: Pointer to the shell_data structure.
 * @str_p: Paths string separated by ':'.
 * @exe: Executable file name.
 * Return: Pointer to the found executable file path.
 * By Kidus Yohannes and Petros Worku.
 */
char *path_finder(shell_data *data, char *str_p, char *exe)
{
	char *path;
	int m = 0, l = 0;

	if (!str_p)
		return (NULL);
	if ((str_length(exe) > 2) && _starting(exe, "./"))
	{
		if (cmd_check(data, exe))
			return (exe);
	}
	while (1)
	{
		if (!str_p[m] || str_p[m] == ':')
		{
			path = char_duplicator(str_p, l, m);
			if (!*path)
				cat_str(path, exe)
			else
			{
				cat_str(path, "/");
				cat_str(path, exe);
			}
			if (cmd_check(data, path))
				return (path);
			if (!str_p[m])
				break;
			l = m;
		}
		m++;
	}
	return (NULL);

}

/**
 * cmd_check - Check if a file exists and is a regular file.
 * @data: Pointer to the shell_data structure.
 * @finder: File path to be checked.
 * Return: 1 if the file exists and is a regular file.
 * By Kidus Yohannes and Petros Worku.
 */
int cmd_check(shell_data *data, char *finder)
{
	struct stat st;

	(void)data;
	if (!finder || stat(finder, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * char_duplicator - Create a duplicate of a character substring.
 * @str_p: Source string.
 * @enter: Starting index of the substring.
 * @finish: Ending index of the substring.
 * Return: Pointer to the duplicated substring.
 * By Kidus Yohannes and Petros Worku.
 */
char *char_duplicator(char *str_p, int enter, int finish)
{
	static char buffer[1024];
	int m = 0, l = 0;

	for (l = 0, m = enter; m < finish; m++)
		if (str_p[m] != ':')
			buffer[l++] = str_p[m];
	buffer[l] = 0;
	return (buffer);
}
int ptr_free(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
			*pointer = NULL;
		return (1);
	}
	return (0);
}
