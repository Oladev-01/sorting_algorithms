#include "sort.h"
/**
 * selection_sort - this is a selection sort algorithm
 * @array: the array of unsorted data
 * @size: the size of the unsorted array of data
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}
			if (idx != i)
			{
				swap(&array[idx], &array[i]);
				print_array(array, size);
			}
	}
}

/**
 * swap - this function swaps A with B
 * @A: this is the first argument that will be swapped
 * with B
 * @B: this will be swapped with A
 * Return: null
 */
void swap(int *A, int *B)
{
	int temp = *A;

	*A = *B;
	*B = temp;
}