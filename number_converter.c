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

