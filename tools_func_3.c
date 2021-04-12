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

void _setenv(char *name, char *value, prm_t *prm)
{
	char *str;
	int ite = 0, ite2 = 0, ite3 = 0;
	char *name2 = calloc(100, sizeof(char));

	if (name2 == NULL)
		perror(prm->name);

	if (name == NULL)
		perror(prm->name);

	while (name[ite] != '\0')
	{
		if (name[ite] == '=')
			perror(prm->name);
		ite++;
	}

	while (environ[ite2] != NULL)
		ite2++;

	_strcat(name2, name);
	_strcat(name2, "=");
	_strcat(name2, value);

	str = _getenv_with_var_name(name);

	if (str == NULL)
	{
		environ[ite2] = name2;
		environ[ite2 + 1] = '\0';
	}
	else if (value != NULL)
	{
		while (environ[ite3] != str)
			ite3++;
		_strcpy(environ[ite3], name2);
		free(name2);
	}
}

void _unsetenv(char *name, prm_t *prm)
{
	char *str;
	int size = 0, ite = 0, pos = 0, ite2 = 0;

	while (environ[size] != NULL)
		size++;

	if (name == NULL)
		perror(prm->name);

	while (name[ite2] != '\0')
	{
		if (name[ite2] == '=')
			perror(prm->name), exit(0);
		ite2++;
	}

	str = _getenv_with_var_name(name);

	while (environ[pos] != str)
		pos++;

	/* Copy next element value to current element */
	for (ite = pos; ite < size; ite++)
	{
		environ[ite] = environ[ite + 1];
	}
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
