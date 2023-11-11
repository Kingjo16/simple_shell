#include "memory.h"

/**
 * length_str - Calculate the length of a string.
 * @string: The input string.
 * Return: The length of the string.
 * By Kidus Yohannes and Petros Worku.
 */
int length_str(char *string)
{
	int m = 0;

	if (!string)
		return (0);

	while (*string++)
		m++;
	return (m);
}

/**
 * compar_str - Compare two strings.
 * @o_ne: The first input string.
 * @t_wo: The second input string.
 * Return: The comparison result.
 * By Kidus Yohannes and Petros Worku.
 */
int compar_str(char *o_ne, char *t_wo)
{
	while (*o_ne && *t_wo)
	{
		if (*o_ne != *t_wo)
			return (*o_ne - *t_wo);
		o_ne++;
		t_wo++;
	}
	if (*o_ne == *t_wo)
		return (0);
	else
		return (*o_ne < *t_wo ? -1 : 1);
}

/**
 * cat_str - Concatenate two strings.
 * @buf: The buffer string to which the source string will be appended.
 * @sour: The source string to be appended to the buffer string.
 * Return: A pointer to the concatenated string.
 * By Kidus Yohannes and Petros Worku.
 */
char *cat_str(char *buf, char *sour)
{
	char *k = buf;

	while (*buf)
		buf++;
	while (*sour)
		*buf++ = *sour++;
	*buf = *sour;
	return (k);
}

/**
 * _starting - Check if one string is a prefix of another string.
 * @bags: The larger string to be checked.
 * @smaller: The smaller string to be checked if it is a prefix of the larger string.
 * Return: A pointer to the remaining characters in the larger string after the prefix.
 * By Kidus Yohannes and Petros Worku.
 */
char *_starting(const char *bags,const char *smaller)
{
	while (*smaller)
		if (*smaller++ != *bags++)
			return (NULL);
	return ((char *)bags);
}
