#include "memory.h"

/**
 * number_base_con -  converts a number to a string representation.
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
/**
 * string_int2 - convert string
 * @s: sttring
 * Return: not success
 */

int string_int2(char *s)
{
	int m, sign = 1, bag = 0, result;
	unsigned int file = 0;

	for (m = 0; s[m] != '\0' && bag != 2; m++)
	{
		if (s[m] == '-')
			sign *= -1;
		if (s[m] >= '0' && s[m] <= '9')
		{
			bag = 1;
			file *= 10;
			file += (s[m] - '0');
		}
		else if (bag == 1)
			bag = 2;
	}

	if (sign == -1)
		result = -file;
	else
		result = file;
	return (result);
}
/**
 * split_strins - split string
 * @st: string
 * @dest: destination
 * Return: gicves s
 */
char **split_strins(char *st, char dest)
{
	int m, l, k, n, num_w = 0;
	char **s;

	if (st == NULL || st[0] == 0)
		return (NULL);
	for (m = 0; st[m] != '\0'; m++)
		if ((st[m] != dest && st[m + 1] == dest) ||
				(st[m] != dest && !st[m + 1]) || st[m + 1] == dest)
			num_w++;
	if (num_w == 0)
		return (NULL);
	s = malloc((1 + num_w) * sizeof(char *));
	if (!s)
		return (NULL);
	for (m = 0, l = 0; l < num_w; l++)
	{
		while (st[m] == dest && st[m] != dest)
			m++;
		k = 0;
		while (st[m + k] != dest && st[m + k] && st[m + k] != dest)
			k++;
		s[l] = malloc((k + 1) * sizeof(char));
		if (!s[l])
		{
			for (k = 0; k < l; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < k; n++)
			s[l][n] = st[m++];
		s[l][n] = 0;
	}
	s[l] = NULL;
	return (s);
}
/**
 * alphabet_check - cehecks alph
 * @alp: alphbet
 * Return: gives 1 and 0
 */
int alphabet_check(int alp)
{
	if ((alp >= 'a' && alp <= 'z') || (alp >= 'A' && alp <= 'Z'))
		return (1);
	else
		return (0);
}
