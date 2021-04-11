#include "shell-header.h"

int _isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int _atoi(char *s)
{
	int operand = 1, size = _strlen(s), i;
	char current;
	unsigned int nb = 0;

	for (i = 0; i < size; i++)
	{
		current = s[i];

		if (_isDigit(current))
		{
			nb *= 10;
			nb *= current - 48;
		}
		else if (current == '-')
		{
			operand = -operand;
		}
		else if (nb > 0)
		{
			break;
		}
	}

	return (operand * nb);
}

void _setenv(char *name, char *value, prm_t *prm)
{
	char *str /*tmp[100]*/;
	int ite = 0, ite2 = 0, ite3 = 0;
	char *name2 = calloc(100, sizeof(char));

	if (name2 == NULL)
		perror(prm->name);

	/*      A faire: gérer les cas d'erreur en les formulant correctement */
	/* possiblement utliser prm->setenv_name == "" ? */

	if (name == NULL)
	{
		perror(prm->name);
	}

	while (name[ite] != '\0')
	{
		if (name[ite] == '=')
		{
			perror(prm->name);
		}
		ite++;
	}

	while (environ[ite2] != NULL)
		ite2++;

	strcat(name2, name);
	strcat(name2, "=");
	strcat(name2, value);

	str = _getenv_with_var_name(name);

	if (str == NULL)
	{
		/* strcat(tmp, name2); */
		environ[ite2] = name2;
		environ[ite2 + 1] = '\0';
		/* free(name2); */
	}
	else if (value != NULL)
	{
		while (environ[ite3] != str)
			ite3++;
		strcpy(environ[ite3], name2);
		free(name2);
	}
}

void _unsetenv(char *name, prm_t *prm)
{
	char *str;
	int size = 0, ite = 0, pos = 0, ite2 = 0;
	extern char **environ;

	while (environ[size] != NULL)
		size++;

	/* A faire: Utiliser prm.setenv_name ou prm->setenv_name selon la manière dont notre struct est formulée */

	/* A faire: là on veutr vérifier uniquement  que la string contenu dans prm.setenv n'est pas nulle */

	if (name == NULL)
	{
		perror(prm->name);
	}

	while (name[ite2] != '\0')
	{
		if (name[ite2] == '=')
			perror(prm->name), exit(0);
		ite2++;
	}

	str = _getenv_with_var_name(name);

	while (environ[pos] != str)
		pos++;

	/* Copy next element value to current element */
	for (ite = pos; ite < size; ite++)
	{
		environ[ite] = environ[ite + 1];
	}
}
