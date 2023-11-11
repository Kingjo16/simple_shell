#include "memory.h"

/**
 * number_base_con - Converts a number to a string representation in a specified base.
 * @num: The number to convert.
 * @b: The base to convert the number to.
 * @flag: Flag indicating conversion options.
 * Return: A pointer to the resulting string in 'buf'.
 * By Kidus Yohannes and Petros Worku.
 */
char *number_base_con(long int num, int b, int flag)
{
	static char buf[50];
	char s = 0;
	char *points;
	static char *ind;
	unsigned long p = num;

	if (!(flag & UNSIGNED_CON) && num < 0)
	{
		p = -num;
		s = '-';
	}
	
	ind = flag & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	points = &buf[49];
	*points = '\0';

	do	{
		*--points = ind[p % b];
		p /= b;
	} while (p != 0);

	if (s)
		*--points = s;
	return (points);
}

/**
 * string_to_int - Converts a string to an integer.
 * @str: The string to convert.
 * Return: The converted integer value if successful, or -1 if an error occurs.
 * By Kidus Yohannes and Petros Worku.
 */
int string_to_int(char *str)
{
	int m = 0;
	unsigned long int list = 0;

	if (*str == '+')
		str++;
	for (m = 0; str[m] != '\0'; m++)
	{
		if (str[m] >= '0' && str[m] <= '9')
		{
			list *= 10;
			list += (str[m] - '0');
			if (list > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (list);
}
