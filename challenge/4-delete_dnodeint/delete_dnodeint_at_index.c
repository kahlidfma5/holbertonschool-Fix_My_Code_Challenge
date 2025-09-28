#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 * @head: Double pointer to the head of the list
 * @index: The index of the node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp, *to_delete;
    unsigned int p = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;

    /* Traverse to the node at the given index */
    while (p < index && tmp != NULL)
    {
        tmp = tmp->next;
        p++;
    }

    if (tmp == NULL) /* index out of range */
        return (-1);

    to_delete = tmp;

    /* If we're deleting the head node */
    if (index == 0)
    {
        *head = to_delete->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        if (to_delete->prev != NULL)
            to_delete->prev->next = to_delete->next;
        if (to_delete->next != NULL)
            to_delete->next->prev = to_delete->prev;
    }

    free(to_delete);
    return (1);
}
