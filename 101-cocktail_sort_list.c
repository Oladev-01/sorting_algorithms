#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked
 *  list of integers using Cocktail Shaker Sort
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end = NULL;
	int swapped = 1;


	if (!list || !(*list) || !(*list)->next)
		return;

	start = *list;
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
		swapped = trav_back(list, &start, swapped);
	}
}

/**
 * trav_back - this function traverses the list from the last
 * @start: the current index
 * @list: the pointer to the start of the list
 * @swapped: this checks if a swap has occurred
 * Return: swapped
 */
int trav_back(listint_t **list, listint_t **start, int swapped)
{
	/* Traverse backward */
	while ((*start)->prev)
	{
		if ((*start)->n < (*start)->prev->n)
		{
			swap_nodes(list, (*start)->prev, (*start));
			print_list(*list);
			swapped = 1;
		}
		else
		{
			(*start) = (*start)->prev;
		}
	}
	return (swapped);
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
