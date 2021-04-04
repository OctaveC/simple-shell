#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - execv+fork+wait demonstration
 *
 * Return: 1 if it fails, or 0 if it succeeds.
 */
int main(void)
{
	pid_t pids[5];
	char *buffer = NULL, *str, *token;
	size_t buffsize = 0;
	int ite;
	int num = 1, ite2, linenum = -1;
	int status;
	pid_t pid;
	char *argv[10];
	char *saveptr;

        /* Start children */
	for (ite = 0; ite <= num; ++num)
	{
		if ((pids[ite] = fork()) < 0)
		{
			perror("fuck");
			return (1);
		}
		else if (pids[ite] == 0)
		{
			printf("$ ");
			linenum = getline(&buffer, &buffsize, stdin);
			printf("\n");
			for (ite2 = 0, str = buffer; ; ite2++, str = NULL)
			{
				token = strtok_r(str, " \n", &saveptr);
				if (token == NULL)
					break;
				argv[ite2] = token;
			}
			argv[ite2] = NULL;
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			printf("This shouldn't ever get printed\n");
			exit(0);
		}

		/* Wait for children to exit */
		pid = wait(&status);
		printf("\n");
		printf("Child process with PID %d exited\n", pid);
		printf("___________________________________________________\n");
		printf("\n");
	}
	return (linenum);
}
