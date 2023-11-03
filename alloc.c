#include "memory.h"

char *memset(char *string, char c, unsigned int num)
{
	unsigned int index;

	for (index = 0; index < num; index++)
		string[m] = c;

	return (string);
}

void free_strings(char **strings)
{

	char **ptr = strings;
	
	if (!strings)
		return;
	while (*strings)
		free(*strings++);
	free(ptr);
}
void *alloc(void *ptr, unsigned int used_s, unsigned int given_s)
{
	char *m;

	if (!ptr)
		return (malloc(given_s));
	if (!given_s)
		return (free(ptr),NULL);

	if (given_s == used_s)
		return (ptr);

	m = malloc(given_s);
	if (!m)
		return NULL;

	used_s = used_s < given_s ? used_s : given_s;
	while (used_s--)

		m[used_s] = ((char *)ptr)[used_s];


	free(ptr);
	return (m);
}
