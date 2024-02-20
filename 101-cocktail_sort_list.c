#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers using Cocktail Shaker Sort
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list, *end = NULL;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;

		/* Traverse forward */
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				start = start->next;
			}
		}

		/* Update the end of the sorted part */
		end = start;

		/* If no swaps were made, break out of the loop */
		if (!swapped)
			break;

		swapped = 0;

		/* Traverse backward */
		while (start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				start = start->prev;
			}
		}
	}
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: first node to be swapped
 * @node2: second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!list || !node1 || !node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}
