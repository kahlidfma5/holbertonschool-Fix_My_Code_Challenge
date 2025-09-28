#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete node at given index
 * @head: double pointer to head
 * @index: index of node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    unsigned int i;
    dlistint_t *to_delete;

    if (head == NULL || *head == NULL)
        return (-1);

    /* Start from head without modifying *head */
    to_delete = *head;
    for (i = 0; i < index && to_delete != NULL; i++)
        to_delete = to_delete->next;

    if (to_delete == NULL)
        return (-1);

    /* Fix links */
    if (to_delete->prev != NULL)
        to_delete->prev->next = to_delete->next;
    else
        *head = to_delete->next;  /* deleted node was head */

    if (to_delete->next != NULL)
        to_delete->next->prev = to_delete->prev;

    free(to_delete);

    return (1);
}
