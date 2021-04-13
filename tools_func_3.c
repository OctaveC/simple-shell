#include "shell-header.h"

/**
 * _isDigit - Checks for digit;
 * @c: digit characters
 * Return: return if between 0 & 9.
 */
int _isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi - Convert string to int;
 * @s: string.
 * Return: return the result of the conversion.
 */
int _atoi(char *s)
{
	int operand = 1, size = _strlen(s), i;
	char current;
	unsigned int nb = 0;

	for (i = 0; i < size; i++)
	{
		current = s[i];

		if (_isDigit(current))
		{
			nb *= 10;
			nb *= current - 48;
		}
		else if (current == '-')
		{
			operand = -operand;
		}
		else if (nb > 0)
		{
			break;
		}
	}

	return (operand * nb);
}

/**
 * _strcat - Concatenate two strings
 * @src: source string
 * @dest: destination string
 * Return: return to destination
 */
char *_strcat(char *dest, char *src)
{
	_strcpy(dest + _strlen(dest), src);

	return (dest);
}
