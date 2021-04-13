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


/**
 * list_s - structure containing useful variables
 * 
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;

} list_t;

/**
 * prm_s - structure containing useful variables
 * 
 */
typedef struct prm_s
{
	char **token_array;
	char *buffer;
	char *name;
	list_t *head;
} prm_t;

/**
 * sh_s -
 * 
 */
typedef struct sh_s
{
	char *data;
	void (*f)(prm_t *);

} sh_t;

extern char **environ;

char *_which(char *argv[], char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strdup(char *str);
char *_getenv(char *name);
char *_strtok(char *str, char *sep, char **saveptr);
unsigned int _strspn(char *s1, char *s2);
unsigned int _strcspn(char *s1, char *s2);
char *_strchr(char *str, char c);
char *_getline(prm_t *prm);
void _puts(char *str);
int _putchar(char c);
void (*check_builtin(char *token))(prm_t *);

void cd_blt(prm_t *prm);
void env_blt(prm_t *prm);
void setenv_blt(prm_t *prm);
void unsetenv_blt(prm_t *prm);
void exit_blt(prm_t *prm);
void help_blt(prm_t *prm);

void free_prm(prm_t *prm);
int _isDigit(char c);
int _atoi(char *s);
char *_getenv_with_var_name(char *name);
void _unsetenv(char *name, prm_t *prm);
void _setenv(char *name, char *value, prm_t *prm);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
list_t *createNodeList(list_t **head, char *str);
size_t print_list(list_t *h);
list_t *env_list(list_t *head);
void free_list(list_t *head);
/* void deleteNodeList(list_t **head, char *str); */
int delete_nodeint_at_index(list_t **head, unsigned int index);
char *_getenvvalue(prm_t *prm, char *name);
char *_getenvnode(prm_t *prm, char *name);

list_t *add_node_end(list_t **head, char *str);
#endif
