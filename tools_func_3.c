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
	char *name2 = _calloc(100, sizeof(char));

	if (name2 == NULL)
	{
		perror(prm->name);
		return;
	}

	if (name == NULL || value == NULL)
	{
		perror(prm->name);
		return;
	}
	while (name[ite] != '\0')
	{
		if (name[ite] == '=')
		{
			perror(prm->name);
			return;
		}
		ite++;
	}

	_strcat(name2, name);
	_strcat(name2, "=");
	_strcat(name2, value);

	str = _getenvnode(prm, name);

	if (str == NULL)
	{
		add_node_end(&prm->head, name2);
	}
	else if (value != NULL)
	{
		_unsetenv(name, prm);
		add_node_end(&prm->head, name2);
	}
}

void _unsetenv(char *name, prm_t *prm)
{
	char *str;
	int size = 0, ite = 0, pos = 0, ite2 = 0;
	list_t *h = prm->head;

	if (name == NULL)
	{
		perror(prm->name);
		return;
	}
	while (name[ite2] != '\0')
	{
		if (name[ite2] == '=')
		{
			perror(prm->name), exit(0);
			return;
		}
		ite2++;
	}

	str = _getenvnode(prm, name);

	while (h->str != str)
	{
		h = h->next;
		pos++;
	}

	delete_nodeint_at_index(&prm->head, pos);
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
