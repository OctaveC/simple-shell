#include "shell-header.h"

void all_execves(char **token_array, char *name)
{
	char *str;
	char *truc;
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
	printf("%s\n", truc);
/*	token_array[1] = NULL; */

/*	while (ite3 <= 9)
	{
		free(token_array[ite3]);
		ite3++;
	}
	free(token_array); */

	if (execve(truc, token_array, NULL) == -1)
	{
		  perror(name);
	}
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

void getline_strtok_and_fork(int *ite, char *buffer, pid_t pids[], char *name)
{
	char *str, *token;
	size_t buffsize = 0;
	int ite2, ite3 = 0, ite4 = 0;
	char **token_array, *saveptr;

	token_array = calloc(sizeof(char), 10);
	while (ite3 <= 9)
	{
		token_array[ite3] = calloc(sizeof(char), 300);
		ite3++;
	}

	if (getline(&buffer, &buffsize, stdin) == EOF)
	{
		free(buffer);
		write(STDIN_FILENO, "\n", 1);
		exit(0);
	}
	for (ite2 = 0, str = buffer;; ite2++, str = NULL)
	{
		token = strtok_r(str, " \n", &saveptr);
		if (token == NULL)
			break;
		printf("test_%s_token\n", token);
		token_array[ite2] = token;
		printf("test_%s_token_array\n", token_array[ite2]);
	}
/*	token_array[ite2] = NULL; */
	while (*token_array[ite4] != '\0')
	{
		printf("test_%s_testHERE\n", token_array[ite4]);
		ite4++;
	}
	token_array[ite2] = NULL;

/*	free(buffer); */

	ite4 = 0;
	printf("\ntruc\n");
/*	while (*token_array[ite4] != '\0')
	{
		printf("test_%s_testHERE2\n", token_array[ite4]);
		ite4++;
		} */
	if ((pids[*(ite)] = fork()) < 0)
	{
		perror(name);
	}
	else if (pids[*(ite)] == 0)
	{
		ite4 = 0;
		printf("\ntruc\n");
		/*	while (*token_array[ite4] != '\0')
		{
			printf("test_%s_testHERE\n", token_array[ite4]);
			ite4++;
			} */
		all_execves(token_array, name);
	}
}

/**
 * main - execv+fork+wait demonstration (WIP)
 *
 * Return: 1 if it fails, or 0 if it succeeds.
 */
int main(int argc, char *argv[])
{
	char *buffer;
	int ite = 0;
	int status;
	pid_t pid;
	pid_t pids[20];
	char *name = argv[0];

	signal(SIGINT, SIG_IGN);

	/* Start children */
	for (ite = 0; ; ite++)
	{
		buffer = calloc(sizeof(char), 300);
		write(1, "$ ", 2);
		getline_strtok_and_fork(&ite, buffer, &pids[20], name);
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
		/*free(buffer); */
	}
	argc = argc;
	return (0);
}
