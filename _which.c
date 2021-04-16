#include "shell-header.h"

/**
 * _which - returns the full path associated with a command
 * @argv: An array contaning our command and its arguments
 * @str: The environemental variable $PATH
 * @prm: test
 *
 * Return: The full path of our command
 */
char *_which(char *argv[], char *str, prm_t *prm)
{
	char *token, *saveptr = NULL, *token2, *name2;
	int ite = 0, check = 0;
	char *c_path = _getenvvalue(prm, "PWD");

	if (!argv[0])
		return ("Error");
	if (!str && c_path != NULL)
	{
		name2 = _calloc(sizeof(char), (_strlen(c_path) + _strlen(argv[0]) + 2));
		_strcat(name2, c_path), _strcat(name2, "/"), _strcat(name2, argv[0]);
		if (access(name2, F_OK) == 0)
		{	free(name2);
			return ("Error");
		}
		free(name2);
	}
	if (!str)
		check = 1;
	if (check == 1 || str[0] == ':' || (argv[0][0] == '.' && argv[0][1] == '/'))
	{
		return (argv[0]);
	}
	for (ite = 1;; ite++, str = NULL)
	{
		token = _strtok(str, ":=", &saveptr);
		if (token == NULL)
			break;
		token2 = _calloc(sizeof(char), (_strlen(token) + _strlen(argv[0]) + 2));
		_strcat(token2, token), _strcat(token2, "/"), _strcat(token2, argv[0]);
		if (access(token2, F_OK) == 0)
			return (token2);
		free(token2);
	}
	if (access(argv[0], F_OK) == 0)
		return (argv[0]);
	return ("Error");
}
