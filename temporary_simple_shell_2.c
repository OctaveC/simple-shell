#include "shell-header.h"

void all_execves(char **token_array, char *name, int *ite, pid_t pids[], char *truc2)
{
	char *str, *dup_truc = NULL, *truc;
	int ite2 = 0, ite3 = 0;
/*	char *test_array[1];
	test_array[1] = '\0'; */


	str = getenv("PATH");
/*	printf("test_%s_test\n", str); */
/*	while (*token_array[ite5] != '\0')
	{
		printf("test_%s_testTRUC3\n", token_array[ite5]);
		ite5++;
		}*/
	truc = _which(token_array, str);
/*	dup_truc = truc; */
/*	printf("%s\n", truc); */
/*	token_array[1] = NULL; */


/*	while (*token_array[ite] != '\0')
		ite++;

	char *static_token_array[ite + 1];

	while (ite2 < ite)
	{
		strcat(static_token_array[ite2], token_array[ite2]);
		ite2++;
	}
	static_token_array[ite2] = '\0'; */
/*
	while (ite3 <= 9)
	{
		free(token_array[ite3]);
		ite3++;
	}
	free(token_array); */
	strcat(truc2, truc);
	free(truc);
	if ((pids[*(ite)] = fork()) < 0)
	{
		perror(name);
	}
	else if (pids[*(ite)] == 0)
	{
		if (execve(truc2, token_array, NULL) == -1)
		{
			perror(name);
		}
		free(truc2);
	}
/*	if (execve(truc, token_array, NULL) == -1)
	{
		perror(name);
	} */
/*	if (execve(token_array[0], token_array, NULL) == -1)
	{
		printf("AGAIN!\n");
		placeholder = token_array[0];
		for (ite = 1; ; ite++, str = NULL)
		{
			token = strtok_r(str, ":=", &saveptr);
			if (token == NULL)
			{
				perror(name);
				} */
			/* printf("%s\n", token); */

/*printf("%s_token\n", token);
  printf("%s_token_array\n", token_array[]); */

	/*	token2 = calloc(100, sizeof(char));
			strcat(token2, token);
			strcat(token2, "/");
			printf("%s_token2_with_/\n", token2);
			strcat(token2, placeholder);
			printf("%s____token2\n", token2);
			token_array[0] = token2;

			if (execve(token_array[0], token_array, NULL) == -1)
			{
			free(buffer);
				  perror(argv[0]);
			}
			free(token2);
		}
		} */
}

void getline_strtok_and_fork(int *ite, pid_t pids[], char *name)
{
	char *token, *stringvoid, *str, *truc2;
	size_t buffsize = NULL;
	int ite2, ite3 = 0, ite4 = 0, length;
	char **token_array, *saveptr, *buffer = NULL;

	if (getline(&buffer, &buffsize, stdin) == EOF)
	{
		free(buffer);
		write(STDIN_FILENO, "\n", 1);
		exit(0);
	}

	token_array = calloc(sizeof(char *), 10);
	truc2 = calloc(sizeof(char), 200);

	str = buffer;

	for (ite2 = 0;; ite2++, str = NULL)
	{
		token = _strtok(str, " \n", &saveptr);
		if (token == NULL)
		{
			free(buffer);
			break;
		}
		token_array[ite2] = calloc(sizeof(char), 200);
		strcat(token_array[ite2], token);
	}

	token_array[ite2] = '\0';


	all_execves(token_array, name, ite, &pids[20], truc2);
/*	if ((pids[*(ite)] = fork()) < 0)
	{
		perror(name);
	}
	else if (pids[*(ite)] == 0)
	{
		all_execves(token_array, name);
		} */

	ite3 = 0;
	while (ite3 < ite2)
	{
		free(token_array[ite3]);
		ite3++;
	}
	free(token_array);
	free(truc2);
}

/**
 * main - execv+fork+wait demonstration (WIP)
 *
 * Return: 1 if it fails, or 0 if it succeeds.
 */
int main(int argc, char *argv[])
{
/*	char *buffer; */
	int ite = 0;
	int status;
	pid_t pid;
	pid_t pids[20];
	char *name = argv[0];

	/* Start children */
	for (ite = 0; ; ite++)
	{
		/*	buffer = calloc(sizeof(char), 300); */
		write(1, "$ ", 2);
		getline_strtok_and_fork(&ite, &pids[20], name);
		/* if (getline(&buffer, &buffsize, stdin) == EOF)
		   {
		   free(buffer);
		   write(STDIN_FILENO, "\n", 1);
		   break;
		   }
		   if ((pids[ite] = fork()) < 0)
		   {
		   perror("fuck");
		   return (1);
		   } */
		/*else if (pids[ite] == 0)
		       {
		for (ite2 = 0, str = buffer;; ite2++, str = NULL)
		{
		token = strtok_r(str, " \n", &saveptr);
		if (token == NULL)
			break;
		token_array[ite2] = token;
	}
		token_array[ite2] = NULL;
		if (execve(token_array[0], token_array, NULL) == -1)
		{
		free(buffer);
		perror(argv[0]);
	}
		exit(0);
	} */

		/* Wait for children to exit */
		pid = wait(&status);
		pid = pid;
		/*	free(buffer); */
	}
	argc = argc;
	return (0);
}
