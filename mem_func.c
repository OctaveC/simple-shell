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
		ptr = _calloc(new_size, 1);
		return (ptr);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	array = _calloc(new_size, 1);

	if (array == NULL)
	{
		free(ptr);
		return (NULL);
	}
	array = _memcpy(array, ptr, old_size);
	free(ptr);
	return (array);
}

/**
 * _memcpy - Copies memory area
 * @dest: copy destination
 * @src: source that we copy
 * @n: n byte that we copy
 * Return: return destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		dest[index] = src[index];
	}

	return (dest);
}
