#include "shell-header.h"

char *_which(char *argv[], char *str)
{
	char *token, *saveptr = NULL, *token2;
	int ite = 0;

	if (str[0] == ':' || argv[0][0] == '.' && argv[0][1] == '/')
	{
		if (access(argv[0], F_OK) == 0)
		{
			return (argv[0]);
		}
	}
	for (ite = 1;; ite++, str = NULL)
	{
		token = _strtok(str, ":=", &saveptr);
		if (token == NULL)
		{
			break;
		}
		token2 = calloc(200, sizeof(char));
		strcat(token2, token);
		strcat(token2, "/");
		strcat(token2, argv[0]);
		if (access(token2, F_OK) == 0)
		{
			return (token2);
		}
		free(token2);
	}
	if (access(argv[0], F_OK) == 0)
	{
		return (argv[0]);
	}
	return ("Error");
}
