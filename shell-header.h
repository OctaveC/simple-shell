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
#include <errno.h>

/**
 * struct list_s - structure containing useful variables
 * @str: environemental variable
 * @next: the next node in the list
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;

} list_t;

/**
 * struct prm_s - structure containing useful variables
 * @token_array: Array contaning the commands passed to our program
 * @buffer: a buffer containing the line returned by getline
 * @name: the name of our program
 * @head: the head of a linked list containing the environement
 * @status: the status of our process at exit.
 * @ite: how many times we have executed a function.
 */
typedef struct prm_s
{
	char **token_array;
	char *buffer;
	char *name;
	int status;
	list_t *head;
	int ite;
} prm_t;

/**
 * struct sh_s - strcuture used to choose the correct built-in
 * @data: the name of the built-in we need
 * @f: a pointer to the built-in function returned
 */
typedef struct sh_s
{
	char *data;
	void (*f)(prm_t *);

} sh_t;

extern char **environ;

/* main functions of our program */
void parsingManager(int *ite, pid_t pids[], prm_t *prm);
void create_child(pid_t pids[], int *ite, prm_t *prm);
void executeCmd(prm_t *prm);

/* function replacing getline */
char *_getline(prm_t *prm);

/* function replacing which */
char *_which(char *argv[], char *str);

/* function replacing strtok */
char *_strtok(char *str, char *sep, char **saveptr);

/* function that checks if a command is a built-in */
void (*check_builtin(char *token))(prm_t *);

/* function that handle errors */
void error_handler(prm_t *prm, char *error_str);

/* built-ins */
void cd_blt(prm_t *prm);
void env_blt(prm_t *prm);
void setenv_blt(prm_t *prm);
void unsetenv_blt(prm_t *prm);
void exit_blt(prm_t *prm);
void help_blt(prm_t *prm);

/* functions replacing getenv */
char *_getenvvalue(prm_t *prm, char *name);
char *_getenvnode(prm_t *prm, char *name);

/* functionq that manipulate the environement */
int _unsetenv(char *name, prm_t *prm);
int _setenv(char *name, char *value, prm_t *prm);
list_t *createNodeList(list_t **head, char *str);
list_t *add_node_end(list_t **head, char *str);
size_t print_list(list_t *h);
list_t *env_list(list_t *head);
list_t *insert_node_at_index(list_t **head, unsigned int idx, char *str);
int delete_node_at_index(list_t **head, unsigned int index);


/* functionq that write text to stdin our stdout */
void _puts(char *str);
int _putchar(char c);

/* various functions used to handle strings */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s1, char *s2);
unsigned int _strcspn(char *s1, char *s2);
char *_strchr(char *str, char c);
int _isDigit(char c);
int _atoi(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_itoa(int num);

/* functions handling memory */
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strdup(char *str);
void free_prm(prm_t *prm);
char *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_list(list_t *head);

#endif
