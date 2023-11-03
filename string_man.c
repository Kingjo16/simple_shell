#include "memory.h"

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

char *str_dup(const char *string)
{
	int len = 0;
	char *net;

	if (!string)
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

int _printchar(char character)
{

	static int m;
	static char buffer[BUFFER_SIZES];

	if (character == FLUSH || m >= BUFFER_SIZES)
	{
		write(1, buffer, m);
		m = 0;
	}

	if (character != FLUSH)
		buffer[m++] = character;
	return (1);
}
