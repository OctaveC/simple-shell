#include "shell-header.h"

/**
 * _which - returns the full path associated with a command
 * @argv: An array contaning our command and its arguments
 * @str: The environemental variable $PATH
 *
 * Return: The full path of our command
 */
char *_which(char *argv[], char *str)
{
	char *token, *saveptr = NULL, *token2, *name2;
	int ite = 0, check = 0;

	if (!argv[0])
		return ("Error");
	if (!str)
		check = 1;
	else if ((argv[0][0] == '.' && !argv[0][1]) ||
		 (argv[0][0] == '/' && !argv[0][1]))
		check = 1;
	else if (argv[0][0] == '.' && argv[0][1] == '.' && !argv[0][2])
		check = 1;
	if (str[0] == ':' || (argv[0][0] == '.' && argv[0][1] == '/') ||
	    (argv[0][0] == '/') || check == 1)
	{
		if (access(argv[0], F_OK) == 0)
			return (argv[0]);
		else
			return ("Error");
	}
	for (ite = 1;; ite++, str = NULL)
	{
		token = _strtok(str, ":=", &saveptr);
		if (token == NULL)
		{
			break;
		}
		token2 = _calloc(sizeof(char), (_strlen(token) + _strlen(argv[0]) + 2));
		_strcat(token2, token);
		_strcat(token2, "/");
		_strcat(token2, argv[0]);
		if (access(token2, F_OK) == 0)
		{
			return (token2);
		}
		free(token2);
	}

	return ("Error");
}
