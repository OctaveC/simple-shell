#include "shell-header.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Print a string
 * @str: String
 */
void _puts(char *str)
{
	int length;

	for (length = 0; str[length] != '\0'; length++)
	{
		_putchar(str[length]);
	}
	_putchar('\n');
}

/**
 * _strcmp - compare two strings
 * @s1: a pointer for the first string
 * @s2: a pointer for the second string
 *
 * Return: Nothing
 */

int _strcmp(char *s1, char *s2)
{
	int t;

	for (t = 0; s1[t] != '\0' && s2[t] != '\0'; t++)
	{
		if (s1[t] != s2[t])
		{
			return (s1[t] - s2[t]);
			/* the strcmp function returns the ascii value of the first */
			/* character that doesn't match between the two string */
		}
	}
	if (s1[t] == s2[t])
	{
		return (0);
	}
	else
	{
		return (s1[t] - s2[t]);
	}
}

/**
 * _strdup - Return a pointet to a newly allocated space in memory
 * @str: Source string
 * Return: return str to a new string dup, NULL if str = NULL,
 * and if dup = NULL
 */
/* char *_strdup(char *str)
{
	char *dup;
	unsigned int i;

	if (str == NULL)
	{
		return (NULL);
	}

	dup = malloc((_strlen(str) + 1) * sizeof(char));

	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		dup[i] = str[i];
	}

	return (dup);
} */

/**
 * _strdup - Returns a pointer to a newly allocated space in memory.
 * @str: String that's going to be copied to the space in memory
 *
 * Return: A pointer to the duplicated string, or NULL
 */
char *_strdup(char *str)
{
	char *array;
	int length = 0, ite;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[length] != '\0')
	{
		length++;
	}

	array = _calloc((length + 1), sizeof(char));
	if (array == NULL)
		return (NULL);

	for (ite = 0; str[ite] != '\0'; ite++)
	{
		array[ite] = str[ite];
	}
	return (array);
}

/**
 * _strcpy - Copy a string to a pointed buffer
 * @src: source string
 * @dest: destination string
 * Return: return to destination
 */
char *_strcpy(char *dest, char *src)
{
	char *result = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (result);
}
