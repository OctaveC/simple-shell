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
 * createNodeList - Creates a linked list
 * @head: The head of the list
 * @str: The string to be added as parameter to the node
 *
 * Return: The address of the new element, or NULL if it failed
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

	return (tmp);
}

/**
 * add_node_end - Adds a node at the end of a linked list
 * @head: The head of the list
 * @str: The address of the string to be inserted into the list
 *
 * Return: The address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, char *str)
{
	int count = 0;
	list_t *h;
	list_t *end_node;

	h = malloc(sizeof(list_t));
	if (h == NULL)
		return (NULL);

	while (str[count] != '\0')
		count++;

	h->str = strdup(str);
	free(str);
	h->next = NULL;
	/* if the head is NULL, it is an empty list */
	if (*head == NULL)
		*head = h;
	else
	{
		/* This instance of our struct will find us the last node */
		end_node = *head;

		/* the last node's next address will necessarily be NULL. */
		while (end_node->next != NULL)
		{
			end_node = end_node->next;
		}

		/* add the h node at the end of the linked list */
		end_node->next = h;
	}
	return (h);
}


/**
 * delete_nodeint_at_index - Deletes the node node at index of a linked list.
 * @head: heading node
 * @index: specified index
 * Return: return 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(list_t **head, unsigned int index)
{
	list_t *node;
	list_t *tmp;
	list_t *freel;
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

/* I assign the next node to a value, then free it, so there's no memleak */
	freel = node->next;
	free(freel->str);

	node->next = tmp->next;
	free(tmp);

	return (1);
}

/**
 * env_list - Turns the environ array into a linked list
 * @head: The head of the list
 *
 * Return: The address of the new element, or NULL if it failed
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

/**
 * _getenvvalue - Search in the environment for a given variable.
 * @prm: our structure, contaning various useful parameters
 * @name: name of the variable to search.
 *
 * Return: The value of the variable.
 */
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

/**
 * _getenvnode - Search in the environment for a given variable.
 * @prm: our structure, contaning various useful parameters
 * @name: name of the variable to search.
 *
 * Return: The environemental variable itself.
 */
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
