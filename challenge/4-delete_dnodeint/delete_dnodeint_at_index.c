#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index
 * of a doubly linked list
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *node;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    node = *head;

    /* Traverse to the node at the given index */
    for (i = 0; i < index && node != NULL; i++)
        node = node->next;

    if (node == NULL)
        return (-1);

    /* Update previous node's next */
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        *head = node->next; /* Deleted node was head */

    /* Update next node's prev */
    if (node->next != NULL)
        node->next->prev = node->prev;

    free(node);
    return (1);
}
