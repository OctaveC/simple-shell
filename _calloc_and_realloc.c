#include "shell-header.h"

/**
 *_calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size bytes
 * Return: pointer
 */
char *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = malloc(nmemb * size);
	if (!s)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		s[i] = 0;
	return (s);
}

/**
 * _realloc - Reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: old allocated size for ptr
 * @new_size: new allocated size for ptr
 *
 * Return: NULL if it fails, a pointer to an array otherwise
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *array;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	free(ptr);
	array = malloc(new_size);
	return (array);
}
