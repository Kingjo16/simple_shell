#include "memory.h"

/**
 * str_copy - Copy a string to a destination string.
 * @destination: The destination string where the source string will be copied.
 * @stringc: The source string to be copied.
 * Return: A pointer to the destination string.
 * By Kidus Yohannes and Petros Worku.
 */
char *str_copy(char *destination, char *stringc)
{
	int m = 0;

	if (destination == stringc || stringc == 0)
		return (destination);

	while (stringc[m])
	{
		destination[m] = stringc[m];
		m++;
	}

	destination[m] = 0;
	return (destination);
}

/**
 * str_dup - Duplicate a string.
 * @string: The string to be duplicated.
 * Return: A pointer to the duplicated string.
 * By Kidus Yohannes and Petros Worku.
 */
char *str_dup(const char *string)
{
	int len = 0;
	char *net;

	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;

	net = malloc(sizeof(char) * (len + 1));
	if (!net)
		return (NULL);
	for (len++; len--;)
		net[len] = *--string;
	return (net);
}

/**
 * _prints - Print a string character by character.
 * @string: The string to be printed.
 * By Kidus Yohannes and Petros Worku.
 */
void _prints(char *string)
{
	int m = 0;

	if (!string)
		return;

	while (string[m] != '\0')
	{
		_printchar(string[m]);
		m++;
	}
}

/**
 * _printchar - Print a single character.
 * @character: The character to be printed.
 * Return: This function does not return a value.
 * By Kidus Yohannes and Petros Worku.
 */
int _printchar(char character)
{

	static int m;
	static char buffer[MAX_BUFFER_SIZE];

	if (character == FLUSH || m >= MAX_BUFFER_SIZE)
	{
		write(1, buffer, m);
		m = 0;
	}

	if (character != FLUSH)
		buffer[m++] = character;
	return (1);
}
