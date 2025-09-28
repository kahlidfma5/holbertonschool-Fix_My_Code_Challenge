#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Free a doubly linked list
 * @head: Pointer to the first element of the list
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *tmp;

    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}
