#include "shell-header.h"

void all_execves(prm_t *prm)
{
	char *str, *str2;
	char *truc;
	int ite3 = 0;

	str = getenv("PATH");

	str2 = strdup(str);

	truc = _which(prm->token_array, str2);

	free(str2);

	if (execve(truc, prm->token_array, environ) == -1)
	{
		while (prm->token_array[ite3])
		{
			free(prm->token_array[ite3]);
			ite3++;
		}
		free(prm->token_array);
		free(prm);
		perror(prm->name);
		exit(0);
	}
}

void create_child(pid_t pids[], int *ite, prm_t *prm)
{
	int status;

	pids[*(ite)] = fork();

	if (pids[*(ite)] == -1)
	{
		perror(prm->name);
		exit(0);
	}
	else if (pids[*(ite)] == 0)
		all_execves(prm);
	else
		waitpid(pids[*(ite)], &status, WUNTRACED);
}

void getline_strtok_and_fork(int *ite, pid_t pids[], prm_t *prm)
{
	void (*f)(prm_t *);
	char *token, *str, *saveptr;
	int ite2, ite3 = 0, len = 0;

	prm->buffer = _getline(prm);

	prm->token_array = calloc(sizeof(char *), 10);

	while (prm->buffer[len] != '\0')
	{
		len++;
	}
	if (prm->buffer[len - 1] == '\n')
	{
		prm->buffer[len - 1] = '\0';
	}

	str = prm->buffer;

	for (ite2 = 0;; ite2++, str = NULL)
	{
		token = _strtok(str, " \t", &saveptr);
		if (token == NULL)
		{
			free(prm->buffer);
			break;
		}
		prm->token_array[ite2] = calloc(sizeof(char), 200);
		strcat(prm->token_array[ite2], token);
		printf("Token_array = %s\n", token);
	}

	if (str == NULL)
	{
		f = check_builtin(prm->token_array[0]);
		if (f != NULL)
		{
			f(prm);
		}
	}

	create_child(pids, ite, prm);

	ite3 = 0;
	while (ite3 < ite2)
	{
		free(prm->token_array[ite3]);
		ite3++;
	}
	free(prm->token_array);
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
int main(int argc __attribute__((unused)), char *argv[])
{
	int ite = 0;
	pid_t pids[20];
	prm_t *prm;

	prm = calloc(sizeof(prm_t), 1);
	prm->name = argv[0];

	signal(SIGINT, CtrlC);

	for (ite = 0;; ite++)
	{
		write(STDIN_FILENO, "$ ", 2);
		getline_strtok_and_fork(&ite, &pids[20], prm);
	}
	return (0);
}
