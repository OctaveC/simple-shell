#include "shell-header.h"

/**
 * _itoa - Construct a string representation of an integer.
 * @num: base value.
 * Return: return the result of the conversion.
 */
char *_itoa(int num)
{
	int ite, rem = 0, len = 0;
	unsigned int num_decoy, unsigned_num;

	char *tmpstring, *resultstring;

	tmpstring = _calloc(sizeof(int), 20);
	if (tmpstring == NULL)
		return (NULL);
	num_decoy = num;
	if (num < 0)
	{
		num_decoy = -num;
	}
	unsigned_num = num_decoy;
	if (num == 0)
	{
		free(tmpstring);
		resultstring = _calloc(sizeof(int), 2);
		resultstring[0] = '0';
		return (resultstring);
	}
	while (num_decoy != 0)
		len++, num_decoy /= 10;
	for (ite = 0; ite < len; ite++)
	{
		rem = unsigned_num % 10;
		unsigned_num = unsigned_num / 10;
		tmpstring[len - (ite + 1)] = rem + '0';
	}
	tmpstring[len] = '\0';
	return (tmpstring);
}

/**
 * error_handler -handles errors
 * @prm: command that you need help with
 * @error_str: the string to print the error.
 */
void error_handler(prm_t *prm, char *error_str)
{
	char *ite_str = _itoa(prm->ite);

	write(STDERR_FILENO, prm->name, _strlen(prm->name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ite_str, _strlen(ite_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, prm->token_array[0], _strlen(prm->token_array[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_str, _strlen(error_str));
	write(STDERR_FILENO, "\n", 1);

	free(ite_str);
}

/**
 * error_handler_cd -handles errors
 * @prm: command that you need help with
 * @error_str: the string to print the error.
 */
void error_handler_cd(prm_t *prm, char *error_str)
{
	char *ite_str = _itoa(prm->ite);

	write(STDERR_FILENO, prm->name, _strlen(prm->name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ite_str, _strlen(ite_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, prm->token_array[0], _strlen(prm->token_array[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_str, _strlen(error_str));
	write(STDERR_FILENO, prm->token_array[1], _strlen(prm->token_array[1]));

	write(STDERR_FILENO, "\n", 1);
	free(ite_str);
}
