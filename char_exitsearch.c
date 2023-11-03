#include "memory.h"

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

char char_loc(char *dest, char ch)
{
	do {
		if (*dest == ch)
			return (dest);
	} while (*dest++ != '\0');

	return (NULL);
}
