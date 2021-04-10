#include "shell-header.h"

/**
 * 
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

    prm->buffer = calloc(sizeof(char), buffersize);
    c = '\0';

    while (c != '\n' && c != EOF)
    {
        rd = read(STDIN_FILENO, &c, 1);
        if (rd == 0)
	{
            free(prm->buffer);
	    free(prm);
            write(STDIN_FILENO, "\n", 1);
            exit(EOF);
        }

        prm->buffer[ite] = c;

	if (ite >= buffersize)
	{
		buffersize += 1;
		prm->buffer = realloc(prm->buffer, sizeof(char) * buffersize);
	}
        ite++;
    }
    prm->buffer[ite] = '\0';

    return (prm->buffer);
}

/* int main()
{
    char *buffer = NULL;
    int i = 0;

    while (i == 0)
    {
        buffer = _getline();
        printf("Test : %s", buffer);
    }

    return (0);
} */
