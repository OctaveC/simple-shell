#include "shell-header.h"

/**
 * help - prints help about the usage of comands
 * @prm - command that you need help with
 */

void help_blt(prm_t *prm)
{

	int opening, reading = 1, writing;
	char c;
	char *path = _calloc(30, sizeof(char));

	if (!prm->token_array[1])
	{
		opening = open("help_files/no_match", O_RDONLY);
		if (opening == -1)
		{
			perror(prm->name);
			return;
		}
	}
	else
	{
		_strcat(path, "help_files/");
		_strcat(path, prm->token_array[1]);

		opening = open(path, O_RDONLY);
		if (opening == -1)
		{
			opening = open("help_files/no_match", O_RDONLY);
			if (opening == -1)
			{
				perror(prm->name);
				return;
			}
		}
	}
	while (reading > 0)
	{
		reading = read(opening, &c, 1);
		writing = write(STDOUT_FILENO, &c, reading);
		if (writing == -1)
		{
			perror(prm->name);
			return;
		}
	}
	close(opening);
	free(path);
	putchar('\n');

/*
	if (_strcmp("help", prm->token_array) == 0)
		puts("This command is used by typing 'help' followed by the command you want to knwo more about\n");
	else if (_strcmp("cd", prm->token_array) == 0)
		puts("This command is used to move your current ditrecotry to by typing 'cd' followed by the directory you want to move")
	else
		puts("I don't know this command, type 'help help' if you're confused about this command's usage\n"); */
}
