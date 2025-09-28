#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete node at given index
 * @head: double pointer to head
 * @index: index to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    unsigned int i;
    dlistint_t *tmp;
    dlistint_t *node;

    if (head == NULL || *head == NULL)
        return (-1);

    node = *head;

    for (i = 0; i < index && node != NULL; i++)
        node = node->next;

    if (node == NULL)
        return (-1);

    /* Delete node and fix links */
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        *head = node->next; /* deleted head */

    if (node->next != NULL)
        node->next->prev = node->prev;

    free(node);

    return (1);
}
