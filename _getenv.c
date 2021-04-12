#include "shell-header.h"

/**
 * _getenv - Search in the environment for a given variable.
 * @name: name of the variable to search.
 * Return: return the value of the variable.
 */
char *_getenv(char *name)
{
	char *envar, *tmp, *envar_return = NULL;
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

	envar_return = _strchr(envar, '=');
	if (envar_return == NULL || envar_return + 1 == NULL)
		return ("");

	return (envar_return + 1);
}

/**
 * _getenv_with_var_name - Search in the environment for a given variable.
 * @name: name of the variable to search.
 * Return: return the value AND the name of the variable.
 */
char *_getenv_with_var_name(char *name)
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
