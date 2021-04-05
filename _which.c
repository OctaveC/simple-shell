#include "shell-header.h"

char *_which(char *argv[], char *str)
{
	char *token, *saveptr = NULL, *token2;
	int ite = 0;

	if (access(argv[0], F_OK) == 0)
	{
		return (argv[0]);
		exit(0);
	}
	for (ite = 1; ; ite++, str = NULL)
	{
		token = strtok_r(str, ":=", &saveptr);
		if (token == NULL)
			break;
		/*printf("%s\n", token); */
		token2 = calloc(100, sizeof(char));
		strcat(token2, token);
		strcat(token2, "/");
		strcat(token2, argv[0]);
		if (access(token2, F_OK) == 0)
		{
			return (token2);
			free(token2);
			exit(0);
		}
		free(token2);
	}

	return ("Error");
}

/*
void main(void)
{
	char *argv[1], *str;

	argv[0] = "ls";
	argv[1] = NULL;
	str = _getenv("PATH");
	_which(argv, str);
} */
