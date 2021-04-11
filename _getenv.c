#include "shell-header.h"

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

/*
int main(void)
{
	char *str;

	str = _getenv("PATH");

	if (str == "" || str == NULL)
		printf("(null)\n");
	else
		printf("%s\n", str);

	str = _getenv_with_var_name("PATH");

	if (str == "" || str == NULL)
		printf("(null)\n");
	else
		printf("%s\n", str);
	return (0);
}
*/
