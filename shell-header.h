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

typedef struct sh_s
{
	char *data;
	void (*f)(int);

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
char *_getline(void);
void _puts(char *str);
int _putchar(char c);
void (*check_builtin(char *token))(int);
void env_blt(int status);
void exit_blt(int status);

#endif
