#include "shell-header.h"

int _isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

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
