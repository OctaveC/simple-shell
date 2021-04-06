#include "shell-header.h"
char *_getenv(char *name)
{
	char *envar, *tmp;
	int ite = 0, ite2 = 0;

	envar = NULL;
	while (environ[ite2] != NULL)
	{
		tmp = environ[ite2];
		for (ite = 0; tmp[ite] == name[ite];)
		{
			ite++;
			if (tmp[ite] == '=' && name[ite] == '\0')
				envar = tmp;
		}
		ite2++;
	}
	return (envar);
}
