#include "lists.h"

/**
 * find_listint_loop - finds the node at which a linked list enters
 * an infinite loop
 * @head: beginning of linked list
 *
 * Return: pointer to beginning of loop, or NULL if none
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL;

	if (head == NULL)
		return (NULL);

	if (head->next != NULL)
		slow = head->next;
	if (slow != NULL)
		fast = slow->next;

	if (slow == fast || fast->next == slow)
		return (head);

	while (fast != NULL)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow == fast)
	{
		while (head != slow)
		{
			fast = slow->next;
			while (fast != slow)
			{
				if (fast == head)
					return (head);
				fast = fast->next;
			}
			if (fast == head)
				return (head);
			head = head->next;
		}
	}

	return (NULL);
}
