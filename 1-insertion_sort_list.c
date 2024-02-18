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
	listint_t *current, *next_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next_node = current->next;

		while (current->prev && current->prev->n > current->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->next = current->next;

			if (temp->prev)
				temp->prev->next = current;
			else
				*list = current;

			current->next = temp;
			temp->prev = current;

			if (temp->next)
				temp->next->prev = temp;

			print_list(*list);
		}

		current = next_node;
	}
}
