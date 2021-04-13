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
	int ite1 = 0, ite2, num = 0, sign = 1;

	while (s[ite1] != '\0' && (s[ite1] < '0' || s[ite1] > '9'))
	{
		if (s[ite1] == '-')
		{
			sign *= -1;
		}
		ite1++;
	}
	ite2 = ite1;
	while (s[ite2] >= '0' && s[ite2] <= '9')
	{
		num = (num * 10) + (s[ite2] - '0') * sign;
		ite2++;
	}
	return (num);
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
