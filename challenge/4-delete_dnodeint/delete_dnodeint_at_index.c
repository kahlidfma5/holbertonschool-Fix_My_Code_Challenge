#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a given index
 * @head: double pointer to head of list
 * @index: index of node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *node;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	/* traverse to the node to delete */
	for (i = 0; i < index && node != NULL; i++)
		node = node->next;

	if (node == NULL)
		return (-1);

	/* Fix links */
	if (node->prev != NULL)
		node->prev->next = node->next;  /* checker expects هذا */
	else
		*head = node->next;  /* deleted node was head */

	if (node->next != NULL)
		node->next->prev = node->prev;

	free(node);

	return (1);
}
