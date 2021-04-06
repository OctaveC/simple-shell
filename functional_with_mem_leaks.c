#include "shell-header.h"

void all_execves(char **token_array, char *name)
{
	char *str;
	char *truc;

	str = getenv("PATH");

	truc = _which(token_array, str);

	if (execve(truc, token_array, NULL) == -1)
	{
		perror(name);
		exit(0);
	}
}

void getline_strtok_and_fork(int *ite, char *buffer, pid_t pids[], char *name)
{
	char *str, *token;
	size_t buffsize = 0;
	int ite2, ite3 = 0;
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
		token = _strtok(str, " \n", &saveptr);
		if (token == NULL)
			break;
		token_array[ite2] = token;
	}
	token_array[ite2] = NULL;

	if ((pids[*(ite)] = fork()) < 0)
	{
		perror(name);
	}
	else if (pids[*(ite)] == 0)
	{
		all_execves(token_array, name);
	}
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
	char *buffer;
	int ite = 0;
	int status;
	pid_t pid;
	pid_t pids[20];
	char *name = argv[0];

	signal(SIGINT, CtrlC);

	/* Start children */
	for (ite = 0;; ite++)
	{
		buffer = calloc(sizeof(char), 300);
		write(1, "$ ", 2);
		getline_strtok_and_fork(&ite, buffer, &pids[20], name);

		/* Wait for children to exit */
		pid = wait(&status);
		pid = pid;
	}
	argc = argc;
	return (0);
}
