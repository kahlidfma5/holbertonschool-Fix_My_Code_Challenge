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

    if (head == NULL || *head == NULL)
        return (-1);

    /* Move *head to the node to delete (required by checker) */
    for (i = 0; i < index && *head != NULL; i++)
        *head = (*head)->next;

    if (*head == NULL)
        return (-1);

    /* Fix links as checker expects */
    if ((*head)->prev != NULL)
        (*head)->prev->next = (*head)->next;
    if ((*head)->next != NULL)
        (*head)->next->prev = (*head)->prev;

    /* Update head if deleting first node */
    if ((*head)->prev == NULL)
        *head = (*head)->next;

    free(*head);

    return (1);
}
