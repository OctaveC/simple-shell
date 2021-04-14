#include "shell-header.h"

/**
 * insert_node_at_index - Inserts node at the nth postion in a linked list.
 * @head: The head of the list
 * @idx: The index of the list where the new node will be added
 * @str: the char we're going to insert into the list
 *
 * Return: the address of the new node, or NULL if it failed
 */

list_t *insert_node_at_index(list_t **head, unsigned int idx, char *str)
{
	unsigned int count;
	list_t *placeholder, *node;

	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = node;
		node->next = NULL;
		return (node);
	}
	else if (idx == 0)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	placeholder = *head;
	for (count = 0; count < (idx - 1); count++)
	{
		if (placeholder->next == NULL)
			return (NULL);
		placeholder = placeholder->next;
	}

	node->next = placeholder->next;
	node->str = _strdup(str);
	placeholder->next = node;

	return (node);
}

/**
 * delete_node_at_index - Deletes the node node at index of a linked list.
 * @head: heading node
 * @index: specified index
 * Return: return 1 if it succeeded, -1 if it failed.
 */
int delete_node_at_index(list_t **head, unsigned int index)
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
