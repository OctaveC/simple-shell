#include "shell-header.h"

/**
 * check_builtin - checks if the user has called one of our built-ins.
 * @token: the string we are checking
 *
 * Return: The function that was matched, or NULL.
 */
void (*check_builtin(char *token))(prm_t *)
{
	sh_t bltin[] = {
		{"exit", exit_blt},
		{"env", env_blt},
		{"setenv", setenv_blt},
		{"unsetenv", unsetenv_blt},
		{"cd", cd_blt},
		{"help", help_blt},
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
