#include "shell-header.h"

/**
 * 
 *
 * 
 */
char *_getline(prm_t *prm)
{
	int rd;
	char c;
	int ite = 0;
	int buffersize = 256;

	prm->buffer = _calloc(sizeof(char), buffersize);
	c = '\0';

	while (c != '\n' && c != EOF)
	{
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free_list(prm->head);
			free(prm->buffer);
			free(prm);
			write(STDIN_FILENO, "\n", 1);
			exit(EOF);
		}

		if (ite >= buffersize - 1)
		{
			buffersize += 2;
			prm->buffer = _realloc(prm->buffer, buffersize - 2, sizeof(char) * buffersize);
		}
		prm->buffer[ite] = c;
		ite++;
	}
	prm->buffer[ite] = '\0';

	return (prm->buffer);
}
