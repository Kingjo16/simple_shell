#include "memory.h"

/**
 * print_str - Prints a string character by character.
 * @p_str: Pointer to the string to be printed.
 * By Kidus Yohannes and Petros Worku.
 */
void print_str(char *p_str)
{
	int index;

	index = 0;
	if (p_str == NULL)
		return;
	while (p_str[index] != '\0')
	{
		print_char(p_str[index]);
		index++;
	}
}

/**
 * print_char - Prints a single character.
 * @fe: The character to be printed.
 * Return: It  returns 1.
 * By Kidus Yohannes and Petros Worku.
 */
int print_char(char fe)
{
	static int m;
	static char buffer[BUFFER_SIZES];

	if (fe == FLUSH || m >= BUFFER_SIZES)
	{
		write(2, buffer, m);
		m = 0;
	}

	buffer[m++] = fe;
	return (1);
}

