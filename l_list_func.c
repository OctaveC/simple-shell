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
			_puts("[0] (nil)\n");
		}
		else
		{
			_puts(h->str);
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

	h->str = _strdup(str);
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
