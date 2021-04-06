#include "shell-header.h"

void executeCmd(char **token_array, char *name, int *ite, pid_t pids[], char *truc2)
{
	char *str, *truc;

	str = getenv("PATH");

	truc = _which(token_array, str);

	strcat(truc2, truc);
	free(truc);
	pids[*(ite)] = fork();

	printf("Hello there it's a test");
	
	if (pids[*(ite)] < 0)
	{
		perror(name);
	}
	else if (pids[*(ite)] == 0)
	{
		if (execve(truc2, token_array, NULL) == -1)
		{
			perror(name);
			exit(0);
		}
		free(truc2);
	}
}

void getline_strtok_and_fork(int *ite, pid_t pids[], char *name)
{
	char *token, *str, *truc2;
	size_t buffsize;
	int ite2, ite3 = 0;
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

	executeCmd(token_array, name, ite, &pids[20], truc2);
	ite3 = 0;
	while (ite3 < ite2)
	{
		free(token_array[ite3]);
		ite3++;
	}
	free(token_array);
	free(truc2);
}

void CtrlC(int i)
{
	i = i;
	write(1, "\n$ ", 3);
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

	signal(SIGINT, CtrlC);

	/* Start children */
	for (ite = 0;; ite++)
	{
		write(1, "$ ", 2);
		getline_strtok_and_fork(&ite, &pids[20], name);

		/* Wait for children to exit */
		pid = wait(&status);
		pid = pid;
	}
	argc = argc;
	return (0);
}
