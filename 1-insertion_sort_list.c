#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 *  of integers in ascending order
 * using the Insertion sort algorithm.
 *
 * @list: A pointer to a pointer to listint_t structure
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *tmp;

	if (!list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		next_node = current->next;
		while (current->prev && current->prev->n > current->n)
		{
			tmp = current->prev;
			current->prev =  tmp->prev;
			tmp->next = current->next;

			if (tmp->prev)
				tmp->prev->next = current;

			else
				*list = current;

			current->next = tmp;
			tmp->prev = current;

			if (tmp->next)
				tmp->next->prev = tmp;
			print_list(*list);
		}
		current = next_node;
	}
}
