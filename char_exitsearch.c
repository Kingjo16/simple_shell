#include "memory.h"

/**
 * copy_str - Copies a portion of a string to a destination string.
 * @s_string: Pointer to the source string.
 * @destination: Pointer to the destination string.
 * @cpy: Number of characters to copy.
 * Return: Returns a pointer to the destination string.
 * By Kidus Yohannes and Petros Worku.
 */
char *copy_str(char *destination, char *s_string, int cpy)
{
	char *dest = destination;
	int m, l;

	m = 0;
	while (s_string[m] != '\0' && m < cpy - 1)
	{
		destination[m] = s_string[m];
		m++;
	}

	if (m < cpy)
	{
		l = m;
		while (l < cpy)
		{
			destination[l] = '\0';
			l++;
		}
	}
	return (dest);
}

/**
 * concat_str - Concatenates a portion of a string to a destination string.
 * @s_string: Pointer to the source string.
 * @destination: Pointer to the destination string.
 * @cpy: Maximum number of characters to concatenate.
 * Return: Returns a pointer to the destination string.
 * By Kidus Yohannes and Petros Worku.
 */
char *concat_str(char *destination, char *s_string, int cpy)
{
	char *dest = destination;
	int m, l;

	m = 0;
	l = 0;
	while (destination[m] != '\0')
		m++;

	while (s_string[l] != '\0' && m < cpy)
	{
		destination[m] = s_string[l];
		m++;
		l++;
	}
	if (l < cpy)
		destination[m] = '\0';
	return (dest);
}

/**
 * char_loc - Finds the first occurrence of a character in a string.
 * @ch: Character to find.
 * @dest: Pointer to the string to search.
 * Return: Returns a pointer to the location
 * of 'ch' in the string, or NULL if 'ch' is not found.
 * By Kidus Yohannes and Petros Worku.
 */
char *char_loc(char *dest, char ch)
{
	do {
		if (*dest == ch)
			return (dest);
	} while (*dest++ != '\0');

	return (NULL);
}
