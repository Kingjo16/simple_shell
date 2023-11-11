#include "memory.h"

/**
 * mem_set - Sets each byte in a block of memory to a specified value.
 * @c: Value to set each byte to.
 * @string: Pointer to the block of memory.
 * @num: Number of bytes to set.
 * Return: Returns a pointer to the modified block of memory.
 * By Kidus Yohannes and Petros worku.
 */
char *mem_set(char *string, char c, unsigned int num)
{
	unsigned int index;

	for (index = 0; index < num; index++)
		string[index] = c;

	return (string);
}

/**
 * free_strings - Frees an array of strings and the array itself.
 * @strings: Pointer to the array of strings.
 * Return: without performing any operations.
 * By Kidus Yohannes and Petros worku.
 */
void free_strings(char **strings)
{

	char **ptr = strings;
	
	if (!strings)
		return;
	while (*strings)
		free(*strings++);
	free(ptr);
}

/**
 * alloc - Reallocates memory for a given block of memory.
 * @used_s: Size of the used portion of the memory block.
 * @given_s: Size of the new memory block to allocate.
 * @ptr: Pointer to the block of memory.
 * Return: Returns a pointer to the new memory block if reallocation is successful, or NULL.
 * By Kidus Yohannes and Petros worku.
 */
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
