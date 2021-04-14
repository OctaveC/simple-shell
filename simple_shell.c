#include "shell-header.h"

/**
 * executeCmd - Calls getenv, which, and then execve
 * @prm: Our structure, contaning various useful variables.
 *
 * Return: Nothing.
 */
void executeCmd(prm_t *prm)
{
	char *str, *str2;
	char *truc;
	int ite3 = 0;

	str = _getenvvalue(prm, "PATH");

	str2 = _strdup(str);

	path = _which(prm->token_array, str2);

	free(str2);

	if (execve(truc, prm->token_array, environ) == -1)
	{
		error_handler(prm, "not found");
		while (prm->token_array[ite3])
		{
			free(prm->token_array[ite3]);
			ite3++;
		}
		free(prm->token_array);
		free_list(prm->head);
		free(prm);
		exit(127);
	}
}

/**
 * create_child - Forks our program for execve.
 * @ite: the number of time our prgram has been called
 * @pids: an array contaning the pids of each child process
 * @prm: Our structure, contaning various useful variables.
 *
 * Return: Nothing.
 */
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
	{
		executeCmd(prm);
	}
	else
	{
		if (waitpid(pids[*(ite)], &status, WUNTRACED) != -1)
		{
			if (WIFEXITED(status))
			{
				prm->status = WEXITSTATUS(status);
			}
		}
		else {
			perror(prm->name);
			exit(1);
		}
	}
}

/**
 * parsingManager - Manage the parsing of the arguments and call our
 * check builtins or fork functions.
 * @ite: the number of time our prgram has been called
 * @pids: an array contaning the pids of each child process
 * @prm: Our structure, contaning various useful variables.
 *
 * Return: Nothing.
 */
void parsingManager(int *ite, pid_t pids[], prm_t *prm)
{
	void (*f)(prm_t *);
	char *token, *str, *saveptr;
	int ite2, ite3 = 0, ite4 = 0, len = 0;

	prm->buffer = _getline(prm);
	prm->token_array = malloc(sizeof(char *) * 10);
	while (ite4 < 10)
	{	prm->token_array[ite4] = NULL;
		ite4++;
	}

	while (prm->buffer[len] != '\0')
		len++;
	if (prm->buffer[len - 1] == '\n')
		prm->buffer[len - 1] = '\0';

	str = prm->buffer;
	for (ite2 = 0;; ite2++, str = NULL)
	{	token = _strtok(str, " \t", &saveptr);
		if (token == NULL)
		{       free(prm->buffer);
			break;
		}
		prm->token_array[ite2] = _calloc(sizeof(char), (_strlen(token) + 1));
		_strcat(prm->token_array[ite2], token);
	}

	if (prm->token_array[0] != NULL)
	{       f = check_builtin(prm->token_array[0]);
		if (f != NULL)
			f(prm);
		else
			create_child(pids, ite, prm);
	}
	while (ite3 < ite2)
	{
		free(prm->token_array[ite3]);
		ite3++;
	}
	free(prm->token_array);
}

/**
 * CtrlC - Is executed when the user uses Ctrl+C.
 * @i: who know why that's there
 * Return: Nothing.
 */
void CtrlC(int i)
{
	i = i;
	write(1, "\n$ ", 3);
}

/**
 * main - Intializes and starts up our shell.
 * @argc: unused attribute
 * @argv: array contaning the arguments passed to our function
 *
 * Return: 1 if it fails, or 0 if it succeeds.
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int ite;
	pid_t pids[256] = {0};
	prm_t *prm;

	prm = malloc(sizeof(prm_t) * 1);
	if (prm == NULL)
	{	perror(argv[0]);
		return (1);
	}

	prm->status = 0;
	prm->head = NULL;
	prm->head = env_list(prm->head);
	if (prm->head == NULL)
	{       perror(argv[0]);
		return (1);
	}
	prm->buffer = "";
	prm->name = argv[0];

	signal(SIGINT, CtrlC);

	for (ite = 1;; ite++)
	{
		prm->ite = ite;
		write(STDIN_FILENO, "$ ", 2);
		parsingManager(&ite, &pids[256], prm);
	}
	return (0);
}
