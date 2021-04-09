#include "shell-header.h"

void all_execves(char **token_array, char *name)
{
	char *str, *str2;
	char *truc;
	int ite3 = 0;

	str = getenv("PATH");

	str2 = strdup(str);

	truc = _which(token_array, str2);

	free(str2);

	if (execve(truc, token_array, environ) == -1)
	{
		while (token_array[ite3])
		{
			free(token_array[ite3]);
			ite3++;
		}
		free(token_array);

		perror(name);

		exit(0);
	}
}

void create_child(pid_t pids[], int *ite, char **token_array, char *name)
{
	int status;

	pids[*(ite)] = fork();

	if (pids[*(ite)] == -1)
	{
		perror(name);
		exit(0);
	}
	else if (pids[*(ite)] == 0)
		all_execves(token_array, name);
	else
		waitpid(pids[*(ite)], &status, WUNTRACED);
}

void getline_strtok_and_fork(int *ite, pid_t pids[], char *name)
{
	void (*f)(int);
	char *token, *str;
	int ite2, ite3 = 0, len = 0;

	char **token_array, *saveptr, *buffer;

	buffer = _getline();

	token_array = calloc(sizeof(char *), 10);

	while (buffer[len] != '\0')
	{
		len++;
	}
	if (buffer[len - 1] == '\n')
	{
		buffer[len - 1] = '\0';
	}

	str = buffer;

	if ((f = check_builtin(str)))
  {
		f(0);
	}

	for (ite2 = 0;; ite2++, str = NULL)
	{
		token = _strtok(str, " \t", &saveptr);
		if (token == NULL)
		{
			free(buffer);
			break;
		}
		token_array[ite2] = calloc(sizeof(char), 200);
		strcat(token_array[ite2], token);
	}

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
	pid_t pids[20];
	char *name = argv[0];

	signal(SIGINT, CtrlC);

	for (ite = 0;; ite++)
	{
		write(STDIN_FILENO, "$ ", 2);
		getline_strtok_and_fork(&ite, &pids[20], name);
	}
	argc = argc;
	return (0);
}
