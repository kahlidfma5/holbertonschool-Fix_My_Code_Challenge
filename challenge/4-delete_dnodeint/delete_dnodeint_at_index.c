#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a given index
 * of a doubly linked list
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    unsigned int i;
    dlistint_t *tmp;

    if (head == NULL || *head == NULL)
        return (-1);

    /* Traverse the list using *head directly */
    for (i = 0; i < index && *head != NULL; i++)
        *head = (*head)->next;

    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        tmp = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
    }
    else
    {
        if ((*head)->prev != NULL)
            (*head)->prev->next = (*head)->next;
        if ((*head)->next != NULL)
            (*head)->next->prev = (*head)->prev;
        free(*head);
        *head = NULL;
    }

    return (1);
}
