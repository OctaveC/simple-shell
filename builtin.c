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

void setenv_blt(prm_t *prm)
{
	char *str;
	int ite = 0, ite2 = 0, ite3 = 0;
	char *name2 = calloc(100, sizeof(char));
	if (name2 == NULL)
	{
		perror(prm->name);
		return;
	}

	if (prm->token_array[1] == NULL || prm->token_array[2] == NULL)
	{
		perror(prm->name);
		return;
	}

	while (prm->token_array[1][ite] != '\0')
	{
		if (prm->token_array[1][ite] == '=')
		{
			perror(prm->name);
			return;
		}
		ite++;
	}

	while (environ[ite2] != NULL)
		ite2++;

	strcat(name2, prm->token_array[1]);
	strcat(name2, "=");
	strcat(name2, prm->token_array[2]);

	str = _getenv_with_var_name(prm->token_array[1]);

	if (str == NULL)
	{
		free(environ[ite2]);
		environ[ite2] = calloc(100, sizeof(char));
		strcat(environ[ite2], name2);
		environ[ite2 + 1] = '\0';
		free(name2);
	}
	else if (prm->token_array[2] != NULL)
	{
		while (environ[ite3] != str)
			ite3++;
	       	strcpy(environ[ite3], name2);
		free(name2);
	}
}

void unsetenv_blt(prm_t *prm)
{
	char *str;
	int size = 0, ite = 0, pos = 0, ite2 = 0;
	extern char **environ;

	while (environ[size] != NULL)
		size++;

	/* A faire: Utiliser prm.setenv_name ou prm->setenv_name selon la manière dont notre struct est formulée */

	/* A faire: là on veutr vérifier uniquement  que la string contenu dans prm.setenv n'est pas nulle */

	if (prm->token_array[1] == NULL)
	{
		perror(prm->name);
	}

	while (prm->token_array[1][ite2] != '\0')
	{
		if (prm->token_array[1][ite2] == '=')
			perror(prm->name), exit(0);
		ite2++;
	}

	str = _getenv_with_var_name(prm->token_array[1]);

	while (environ[pos] != str)
		pos++;

	/* Copy next element value to current element */
	for (ite = pos; ite < size; ite++)
	{
		environ[ite] = environ[ite + 1];
	}
}

void cd_blt(prm_t *prm)
{
	int chdir_return;
	char buffer_cwd[500];

	if (prm->token_array[1] == NULL || prm->token_array[1][0] == '~')
		chdir_return = chdir(_getenv("HOME"));
	else if (prm->token_array[1][0] == '-' && !prm->token_array[1][1])
	{
		chdir_return = chdir(_getenv("OLDPWD"));
		_puts(getcwd(buffer_cwd, 500));
	}
	else
		chdir_return = chdir(prm->token_array[1]);

	if (chdir_return == -1)
	{
		perror(prm->name);
		return;
	}

	_setenv("OLDPWD", _getenv("PWD"), prm);
	_setenv("PWD", getcwd(buffer_cwd, 500), prm);
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
	    {"setenv", setenv_blt},
	    {"unsetenv", unsetenv_blt},
	    {"cd", cd_blt},
	    {NULL, NULL}
	};
	int ite = 0;

	while ((bltin + ite)->data)
	{
		if (_strcmp(token, (bltin + ite)->data) == 0)
		{
			return ((bltin + ite)->f);
		}
		ite++;
	}

	return (NULL);
}
