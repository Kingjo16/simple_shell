#include "memory.h"

int length_str(char *string)
{
	int m = 0;

	if (!string)
		return (0);

	while (*string++)
		m++;
	return (m);
}

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
char *_starting(const char *bags,const char *smaller)
{
	while (*smaller)
		if (*smaller++ != *bags++)
			return (NULL);
	return ((char *)bags);
}
