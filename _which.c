#include "shell-header.h"

char *_which(char *argv[], char *str)
{
	char *token, *saveptr = NULL, *token2;
	int ite = 0, check = 0;

	printf("\nDo we Reach here? 9\n");

	if (!str || !str[0])
		return ("Error");
	if (!argv)
	{
		printf("\nDo we Reach here? 18\n");
	}
	if (!argv[0])
	{
		printf("\nDo we Reach here? 19\n");
		return ("Error");
	}
	if (!argv[0][0])
	{
		printf("\nDo we Reach here? 20\n");
	}
	if (!argv[0][1])
	{
		printf("\nDo we Reach here? 21\n");
		/*	return("Error"); */
	}
	if ((argv[0][0] == '.' && !argv[0][1]) || (argv[0][0] == '/' && !argv[0][1]))
		check = 1;
	else if (argv[0][0] == '.' && argv[0][1] == '.' && !argv[0][2])
		check = 1;
	if (str[0] == ':' || (argv[0][0] == '.' && argv[0][1] == '/') || check == 1)
	{
		printf("\nDo we Reach here? 14\n");
		if (access(argv[0], F_OK) == 0)
		{
			printf("\nDo we Reach FUCKING here? 10\n");
			return (argv[0]);
		}
	}
	printf("\nDo we Reach here? 15\n");
	for (ite = 1;; ite++, str = NULL)
	{
		printf("\nDo we Reach here? 13\n");
		token = _strtok(str, ":=", &saveptr);
		if (token == NULL)
		{
			printf("\nDo we Reach here? 22\n");
			break;
		}
		token2 = calloc(200, sizeof(char));
		strcat(token2, token);
		strcat(token2, "/");
		strcat(token2, argv[0]);
		if (access(token2, F_OK) == 0)
		{
			printf("\nDo we Reach here? 7\n");
			return (token2);
		}
		printf("\nDo we Reach here? 26\n");
		free(token2);
	}
	printf("\nDo we Reach here? 11\n");
	if (access(argv[0], F_OK) == 0)
	{
		printf("\nDo we Reach here? 8\n");
		return (argv[0]);
	}

	printf("\nDo we Reach here? 6\n");
	return ("Error");
}
