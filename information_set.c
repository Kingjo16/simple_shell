#include "memory.h"

/**
 * set_command_data - Sets command-related data in the shell data structure.
 * @data: Pointer to the shell data structure.
 * @argVal: Array of argument values.
 * By Kidus Yohannes and petros Worku.
 */
void set_command_data(shell_data *data, char ** argVal)
{
	int a_index = 0;

	data->command_name = argVal[0];
	if (data->argu)
	{
		data->argu_val = split_str(data->argu, " \t");
		if (!data->argu_val)
		{

			data->argu_val = malloc(sizeof(char *) * 2);
			if (data->argu_val)
			{
				data->argu_val[0] = str_dup(data->argu);
				data->argu_val[1] = NULL;
			}
		}

		for (a_index = 0; data->argu_val && data->argu_val[a_index]; a_index++)
			;
		data->argu_count = a_index;

		cmd_alias_replace(data);
		cmd_var_replace(data);
	}
}

/**
 * split_str - Splits a string into an array of substrings.
 * @s: Pointer to the string to be split.
 * @del: Pointer to the delimiter string.
 * Return: NULL
 * By Kidus Yohannes and petros Worku.
 */
char **split_str(char *s, char *del)
{
	int m, l, k, word_len, wordz = 0;
	char **split_strs;

	if (!s || s[0])
		return (NULL);
	if (!del)
		del = " ";
	for (m = 0; s[m] != '\0'; m++)

		if (!del_check(s[m], del) && (del_check(s[m + 1], del) || !s[m + 1]))
		wordz++;
	if (wordz == 0)
		return (NULL);

	split_strs = malloc((1 + wordz) * sizeof(char *));

	if (!split_strs)
		return (NULL);

	for (m = 0, l = 0; l < wordz; l++)
	{
		while (del_check(s[m], del))
			m++;

		k = 0;

		while (!del_check(s[m + k], del) && s[m + k])
			k++;
		split_strs[l] = malloc((k + 1) * sizeof(char));

		if (!split_strs[l])
		{
			for (k = 0; k < l; k++)
				free(split_strs[k]);

			free(split_strs);
			return (NULL);
		}
		for (word_len = 0; word_len < k; word_len++)
			split_strs[l][word_len] = s[m++];
		split_strs[l][word_len] = 0;
	}

	split_strs[l] = NULL;
	return (split_strs);
}

/**
 * del_check - Checks if a character is a delimiter.
 * @del: Pointer to the delimiter string.
 * @char_delim: The character to check.
 * Return: If no match is found, the function returns 0 to indicate that 'char_delim' is not a delimiter.
 * By Kidus Yohannes and petros Worku.
 */
int del_check(char char_delim, char *del)
{
	while (*del)
	{
		if (*del++ == char_delim)
		{
			return (1);
		}
	}

		return (0);
}

/**
 * string_cmd_replace - Replaces a string with a new string.
 * @replaced: Pointer to the pointer of the string to be replaced.
 * @new: Pointer to the new string.
 * Return: it returns 1 to indicate a successful replacement.
 * By Kidus Yohannes and petros Worku.
 */
int string_cmd_replace(char **replaced, char *new)
{
	free(*replaced);
	*replaced = new;
	return (1);
}
