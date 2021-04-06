#include "shell-header.h"

char *_which(char *argv[], char *str)
{
	char *token, *saveptr = NULL, *token2;
	int ite = 0;

/*	token2[0] = '\0'; */
	if (access(argv[0], F_OK) == 0)
	{
		return(argv[0]);
	}
	for (ite = 1; ; ite++, str = NULL)
	{
		token = _strtok(str, ":=", &saveptr);
		if (token == NULL)
		{
			/*	free(token2); */
			break;
		}
		/*printf("%s\n", token); */
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

	return ("Error");
}
