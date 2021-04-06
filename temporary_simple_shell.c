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
		free(token_array);
		exit(0);
	}
}

void create_child(pid_t pids[], int *ite, char **token_array, char *name)
{
	pids[*(ite)] = fork();

	if (pids[*(ite)] < 0)
		perror(name);
	else if (pids[*(ite)] == 0)
		all_execves(token_array, name);
}

void getline_strtok_and_fork(int *ite, pid_t pids[], char *name)
{
	char *token, *str;
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

	create_child(pids, ite, token_array, name);

	ite3 = 0;
	while (ite3 < ite2)
	{
		free(token_array[ite3]);
		ite3++;
	}
	free(token_array);
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
		pid = wait(&status);
		pid = pid;
	}
	argc = argc;
	return (0);
}
