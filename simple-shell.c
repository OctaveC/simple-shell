#include "shell-header.h"

/**
 * main - execv+fork+wait demonstration (WIP)
 *
 * Return: 1 if it fails, or 0 if it succeeds.
 */
int main(int argc, char *argv[])
{
	pid_t pids[5];
	char *buffer, *str, *token;
	size_t buffsize = 0;
	int ite = 0;
	int ite2, linenum = -1;
	int status;
	pid_t pid;
	char *token_array[50];
	char *saveptr;

	/* Start children */
	while (buffer != NULL)
	{
		write(1, "$ ", 2);
		if (getline(&buffer, &buffsize, stdin) == EOF)
		{
			write(STDIN_FILENO, "\n", 1);
			break;
		}
		if ((pids[ite] = fork()) < 0)
		{
			perror("fuck");
			return (1);
		}
		else if (pids[ite] == 0)
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
				perror(argv[0]);
			}
			exit(0);
		}

		/* Wait for children to exit */
		pid = wait(&status);
		pid = pid;
	}
	argc = argc;
	return (linenum);
}
