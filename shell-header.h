#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct list_s
{
	char *data;
	struct list_s *next;
	struct list_s *prev;

} list_t;

char *_which(char *argv[], char *str);
int _strlen(const char *s);
char *_strdup(char *str);
char *_getenv(char *name);
size_t print_list(const list_t *h);
list_t *createNodeList(list_t **head, const char *str);
int _setenv(char *name, const char *value, int overwrite);
int _unsetenv(char *name);

#endif
