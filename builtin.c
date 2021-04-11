#include "shell-header.h"

void exit_blt(prm_t *prm)
{
	int ite2 = 0;
	int extcode = EXIT_SUCCESS;

	if (prm == NULL)
	{
		return;
	}

	if (prm->token_array[1] != NULL)
	{
		extcode = _atoi(prm->token_array[1]);
	}
	while (prm->token_array[ite2] != NULL)
	{
		free(prm->token_array[ite2]);
		ite2++;
	}
	free(prm->token_array);
	free(prm);
	exit(extcode);
}

void env_blt(prm_t *prm __attribute__((unused)))
{
	int ite = 0;

	while (environ[ite] != NULL)
	{
		_puts(environ[ite]);
		ite++;
	}
}

/**
 * 
 * 
 */
void (*check_builtin(char *token))(prm_t *)
{
	sh_t bltin[] = {
	    {"exit", exit_blt},
	    {"env", env_blt},
	    {NULL, NULL}
	};
	int ite = 0;

	while ((bltin + ite)->data)
	{
		if (strcmp(token, (bltin + ite)->data) == 0)
		{
			return ((bltin + ite)->f);
		}
		ite++;
	}

	return (NULL);
}
