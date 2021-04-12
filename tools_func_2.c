#include "shell-header.h"

/**
 * _strtok - Break string into multiple tokens using separators.
 * @str: string to check.
 * @sep: separator characters
 * @saveptr: a pointer that maintain the successive
 * calls during the string check.
 * Return: return a pointer to the first token found in the string;
 * otherwise return NULL if there's no tokens left.
 */
char *_strtok(char *str, char *sep, char **saveptr)
{
	char *end = NULL;

	if (str == NULL)
		str = *saveptr;

	if (*str == '\0')
	{
		*saveptr = str;
		return (NULL);
	}

	str += _strspn(str, sep);

	if (*str == '#')
	{
		*saveptr = str;
		return (NULL);
	}

	if (*str == '\0')
	{
		*saveptr = str;
		return (NULL);
	}

	end = str + _strcspn(str, sep);

	if (*end == '\0')
	{
		*saveptr = end;
		return (str);
	}

	*end = '\0';
	*saveptr = end + 1;
	return (str);
}

/**
 * _strspn - return the length of the substring that contain
 * only accepted characters.
 * @s1: string to check.
 * @s2: reference string
 * Return: return the length if success otherwise NULL.
 */
unsigned int _strspn(char *s1, char *s2)
{
	unsigned int len = 0;

	while (s1[len])
		/* return s1 char position if found in s2 using strchr */
	{
		if (_strchr(s2, s1[len]) != NULL)
		{
			len++;
		}
		else
		{
			break;
		}
	}

	return (len);
}

/**
 * _strcspn - return the length of the substring that do not contain
 * the rejected characters.
 * @s1: string to check
 * @s2: reference string
 * Return: return the length if success otherwise NULL.
 */
unsigned int _strcspn(char *s1, char *s2)
{
	unsigned int len = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
		{
			return (len);
		}
		else
		{
			s1++;
			len++;
		}
	}

	return (len);
}

/**
 * _strchr - check for specified character in a string
 * @str: the string
 * @c: the specified character
 * Return: return our string if true, otherwise NULL if false.
 */
char *_strchr(char *str, char c)
{
	char *find = NULL;

	if (str != NULL)
	{
		do {
			if (*str == c)
			{
				find = str;
				break;
			}
		} while (*str++);
	}

	return (find);
}

/**
 * _strlen - Returns lenght of a string.
 * @s: string
 * Return: Return result
 */
int _strlen(char *s)
{
	int length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}
