#include "memory.h"

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
