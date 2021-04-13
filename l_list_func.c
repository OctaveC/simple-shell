#include "shell-header.h"

/**
 * print_list - Prints all the lelements of a list_t list.
 * @h: node
 * Return: return the number of nodes.
 */
size_t print_list(list_t *h)
{
	int i = 0;

	if (h == NULL)
	{
		return (0);
	}

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("%s\n", h->str);
		}
		h = h->next;
		i++;
	}

	return (i);
}

/**
 * 
 * 
 */
list_t *createNodeList(list_t **head, char *str)
{
	list_t *node;
	list_t *tmp;

	tmp = *head;
	if (head == NULL)
	{
		perror("Critical Error");
	}

	node = malloc(sizeof(list_t));

	if (node == NULL)
	{
		perror("Memory can not be allocated");
	}

	node->str = _strdup(str);
	/* printf("%s\n", node->str); */
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (*head);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = node;

	/* free(str); */
	return (tmp);
}

/**
 * delete_nodeint_at_index - Deletes the node node at index of a linked list.
 * @head: heading node
 * @index: specified index
 * Return: return 1 if it succeeded, -1 if it failed.
 */
/* void deleteNodeList(list_t **head, char *str)
{
	list_t *node;
	list_t *tmp;

	node = *head;

	if (*head == NULL)
	{
		perror("Critical Error");
	}

	while (node->next != NULL)
	{
		if (_strcmp(str, node->str) == 0)
		{
			break;
		}
		tmp = node;
	}

	if (node != NULL)
	{
		if (node == *head)
		{
			*head = node->next;
		}
		else
		{
			tmp->next = node->next;
		}
	} */

	/* free(node); */ /*
} */

int delete_nodeint_at_index(list_t **head, unsigned int index)
{
	list_t *node;
	list_t *tmp;
	unsigned int i;

	tmp = *head;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	for (i = 0; i < index; i++)
	{
		node = tmp;
		if (tmp->next == NULL)
		{
			return (-1);
		}
		tmp = tmp->next;
	}
	free(node->str);
	node->next = tmp->next;
	free(tmp);

	return (1);
}

/**
 * 
 * 
 */
list_t *env_list(list_t *head)
{
	int ite = 0;

	while (environ[ite] != NULL)
	{
		createNodeList(&head, environ[ite]);
		ite++;
	}

	return (head);
}

/**
 * free_list - Frees a list_t list.
 * @head: Beginning node of our list.
 */
void free_list(list_t *head)
{
	if (head == NULL)
	{
		return;
	}

	free_list(head->next);
	free(head->str);
	free(head);
}

char *_getenvvalue(prm_t *prm, char *name)
{
	char *envar, *tmp, *envar_return = NULL;
	int ite = 0;
	list_t *h; 

	h = prm->head;
	envar = NULL;
	while (h != NULL)
	{
		tmp = h->str;
		for (ite = 0; tmp[ite] == name[ite];)
		{
			ite++;
			if (tmp[ite] == '=' && name[ite] == '\0')
				envar = tmp;
		}
		h = h->next;
	}

	envar_return = _strchr(envar, '=');
	if (envar_return == NULL || envar_return + 1 == NULL)
		return ("");

	return (envar_return + 1);
}

char *_getenvnode(prm_t *prm, char *name)
{
	char *envar, *tmp;
	int ite = 0;
	list_t *h;

	h = prm->head;
	envar = NULL;
	while (h != NULL)
	{
		tmp = h->str;
		for (ite = 0; tmp[ite] == name[ite];)
		{
			ite++;
			if (tmp[ite] == '=' && name[ite] == '\0')
				envar = tmp;
		}
		h = h->next;
	}

	return (envar);
}
