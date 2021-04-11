#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

typedef struct prm_s
{
	char **token_array;
	char *buffer;

} prm_t;

typedef struct sh_s
{
	char *data;
	void (*f)(prm_t *);

} sh_t;

extern char **environ;

char *_which(char *argv[], char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *_getenv(char *name);
char *_strtok(char *str, char *sep, char **saveptr);
unsigned int _strspn(char *s1, char *s2);
unsigned int _strcspn(char *s1, char *s2);
char *_strchr(char *str, char c);
int _setenv(char *name, const char *value, int overwrite);
int _unsetenv(char *name);
char *_getline(prm_t *prm);
void _puts(char *str);
int _putchar(char c);
void (*check_builtin(char *token))(prm_t *);
void env_blt(prm_t *prm);
void exit_blt(prm_t *prm);
void free_prm(prm_t *prm);
int _isDigit(char c);
int _atoi(char *s);

#endif
