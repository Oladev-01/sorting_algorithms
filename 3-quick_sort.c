#include "sort.h"

/**
 * quick_sort_1 - this is a quick sorting algorithm
 * @array: this is an array of unsorted data
 * @low: The lowest index of the current partition
 * @hi: The highest index of the current partition
 * @size: The size of the original array
 *
 * Return: void
 */
void quick_sort_1(int *array, size_t low, size_t hi, size_t size)
{
	int pivot_idx;

	/*Limiting the indexes to size will ensure any conversion of -ves*/
	/*to size_t (unsigned long int) will be ignored (since -ve numbers*/
	/*converted to size_t will produce a very large number)*/
	if (low < size && hi < size && low < hi)
	{
		pivot_idx = Lomuto(array, low, hi, size);

		quick_sort_1(array, low, pivot_idx - 1, size);
		quick_sort_1(array, pivot_idx + 1, hi, size);
	}
}

/**
 * Lomuto - this implmemets lomuto partition scheme
 * @array: the array of unsorted data
 * @low: the first index
 * @last: choosen as the pivot in this case
 * @size: the size of the original array
 *
 * Return: the index of the pivot
 */
int Lomuto(int *array, size_t low, size_t last, size_t size)
{

	size_t idx_pivot, cur_idx;
	int pivot;

	pivot = array[last];
	idx_pivot = low;
	for (cur_idx = low + 1; cur_idx < last; cur_idx++)
	{

		/*Swap items smaller than or equal to pivot to the lower side*/
		if (array[cur_idx] <= pivot)
		{
			swap(&array[idx_pivot], &array[cur_idx]);
		}

		/*Ensure idx_pivot tracks the center of the partition*/
		if (array[idx_pivot] <= pivot)
			idx_pivot++;
	}

	/*If pivot is the largest item in the list no swapping necessary*/
	if (array[idx_pivot] > pivot)
	{
		swap(&array[idx_pivot], &array[last]);
	}
	else
		idx_pivot = cur_idx;
	print_array(array, size);

	return (idx_pivot);
}

/**
 * swap - this function swaps a with b
 * @a: this is the first argument that will be swapped
 * with b
 * @b: this will be swapped with a
 *
 * Return: null
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * quick_sort - this is a quick sorting algorithm
 * @array: this is an array of unsorted data
 * @size: this is the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_1(array, 0, size - 1, size);
}
