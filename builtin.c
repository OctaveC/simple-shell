#include "shell-header.h"

void exit_blt(int status)
{
	exit(status);
}

void env_blt(int status __attribute__((unused)))
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

/*      A faire: Utiliser prm.setenv_name ou prm->setenv_name selon la manière dont notre struct est formulée */

	if (name2 == NULL)
		perror(prm->name), exit(0);

/*      A faire: gérer les cas d'erreur en les formulant correctement */
/* possiblement utliser prm->setenv_name == "" ? */

/*	if (prm->setenv_name == NULL || prm->setenv_name == NULL || equal_sign_alert == 1;)
	perror(prm.name), exit(0); */

	while (prm.setenv_name != '\0')
	{
		if (prm.setenv_name == '=')
			perror(prm.name), exit(0)
	}

	while (environ[ite2] != NULL)
		ite2++;

	strcat(name2, prm.setenv_name);
	strcat(name2, "=");
	strcat(name2, prm.setenv_value);

	str = _getenv(prm.setenv_name);

	if (str == NULL)
	{
		environ[ite2] = name2;
		environ[ite2 + 1] = '\0';
	}
	else if (value != NULL)
	{
		while (environ[ite3] != str)
			ite3++;
		environ[ite3] = name2;
	}

	free(name2);
}

void unsetenv_blt(prm_t *prm)
{
	char *str;
	int size = 0, ite = 0, pos = 0;
	extern char **environ;

	while (environ[size] != NULL)
		size++;

	/* A faire: Utiliser prm.setenv_name ou prm->setenv_name selon la manière dont notre struct est formulée */

	/* A faire: là on veutr vérifier uniquement  que la string contenu dans prm.setenv n'est pas nulle */

	if (prm->setenv_name == NULL)
		perror(prm.name), exit(0);

	while (prm.setenv_name != '\0')
	{
		if (prm.setenv_name == '=')
			perror(prm.name), exit(0);
	}

	str = _getenv(prm.setenv_name);

	while (environ[pos] != str)
		pos++;

        /* Copy next element value to current element */
        for (ite = pos ; ite < size ; ite++)
        {
		environ[ite] = environ[ite + 1];
        }
}

void cd_blt(prm_t *prm)
{
	int ite = 0;

	if (prm->cd_directory == NULL)
		chdir();
}

/**
 * 
 * 
 */
void (*check_builtin(char *token))(int)
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
