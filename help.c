#include "shell-header.h"

/**
 * help_blt - prints help about the usage of comands
 * @prm: command that you need help with
 */
void help_blt(prm_t *prm)
{
	int opening, reading = 1, writing;
	char c, *path = _calloc(30, sizeof(char));

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
	_putchar('\n');
}
