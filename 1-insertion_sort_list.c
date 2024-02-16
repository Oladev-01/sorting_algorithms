#include "sort.h"
/**
 * insertion_sort_list - thiS is an insertion sorting algorithm
 * @list: this is pointer to a pointer to listint_t structure
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{

	listint_t *ptr, *current;
	int next_num, *tmp, *hold;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ptr = (*list)->next;

	while (ptr)
	{
		next_num = ptr->n;
		current = ptr->prev;
		while (current && (current->n > next_num))
		{
			tmp = (int *)&current->next->n;
			*tmp = current->n;
			current = current->prev;
			print_list(*list);
		}
		if (current == NULL)
		{
			hold = (int *)&(*list)->n;
			*hold = next_num;
		}
		else
		{
			hold = (int *)&current->next->n;
			*hold = next_num;
		}
		ptr = ptr->next;
	}
}
