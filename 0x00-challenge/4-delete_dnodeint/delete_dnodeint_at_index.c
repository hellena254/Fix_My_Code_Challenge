#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    unsigned int i;

    if (*head == NULL)
    {
        return (-1);
    }

    current = *head;

    if (index == 0)
    {
        *head = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
        free(current);
        return (1);
    }

    *head = current;  // Reset *head to the saved_head value
    for (i = 0; i < index && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        *head = current;  // Reset *head to the saved_head value
        return (-1);
    }

    if (current->next != NULL)
        current->next->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
    *head = current;  // Reset *head to the saved_head value
    return (1);
}

