#include "shell-header.h"

/**
 * 
 * 
 *
 * 
 */
char *_getline(void)
{
    int rd;
    char c;
    char *buffer;
    int ite = 0;
    int buffersize = 256;

    buffer = calloc(sizeof(char), buffersize);
    c = '\0';

    while (c != '\n' && c != EOF)
    {
        rd = read(STDIN_FILENO, &c, 1);
        if (rd == 0)
	{
            free(buffer);
            write(STDIN_FILENO, "\n", 1);
            exit(EOF);
        }

        buffer[ite] = c;

	if (ite >= buffersize)
	{
		buffersize += 1;
		buffer = realloc(buffer, sizeof(char) * buffersize);
	}
        ite++;
    }
    buffer[ite] = '\0';

    return (buffer);
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
