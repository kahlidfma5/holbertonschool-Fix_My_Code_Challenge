#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a doubly linked list
 * @head: Address of the pointer to the first element of the list
 * @n: Value to store in the new element
 *
 * Return: Pointer to the new element, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new, *l;

    if (head == NULL) /* validate pointer to head */
        return (NULL);

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL) /* empty list */
    {
        *head = new;
        return (new);
    }

    l = *head;
    while (l->next != NULL)
        l = l->next;

    l->next = new;
    new->prev = l;

    return (new);
}
