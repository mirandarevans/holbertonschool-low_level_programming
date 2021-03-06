#include "lists.h"

/**
 * pop_listint - pops the last node off of a linked list
 * @head: pointer to pointer to beginning of list
 *
 * Return: value of node that was popped off
 */
int pop_listint(listint_t **head)
{
	int ret;
	listint_t *to_del;

	if (head == NULL || *head == NULL)
		return (0);

	ret =  (*head)->n;
	to_del = *head;

	*head = (*head)->next;
	free(to_del);
	return (ret);
}
