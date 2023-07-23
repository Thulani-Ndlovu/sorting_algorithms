#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list in ascending order
* @list: doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *target = NULL;
	listint_t *node = *list;

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (node != NULL)
	{
		listint_t *Next = node->next;

		if (target == NULL || node->n <= target->n)
		{
			node->prev = NULL;
			node->next = target;
			if (target != NULL)
				target->prev = node;
			target = node;
		}
		else
		{
			listint_t *tmp = target;

			while (tmp->next != NULL && tmp->next->n < node->n)
				tmp = tmp->next;
			node->next = tmp->next;
			node->prev = tmp;
			if (tmp->next != NULL)
				tmp->next->prev = node;
			tmp->next = node;
		}
		print_list(target);
		node = Next;
	}
	*list = target;
}
