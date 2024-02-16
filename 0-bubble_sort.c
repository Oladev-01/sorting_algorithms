#include "sort.h"
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

/**
 * bubble_sort - this function implements the bubble sorting algorithm
 * @array: this is the array of unsorted data
 * @size: this is the size of the array
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t first, second;
	bool swapped;

	if (array == NULL)
		return;

	for (first = 0; first < size - 1; first++)
	{
		swapped = false;
		for (second = 0; second < size - first - 1; second++)
		{
			if (array[second] > array[second + 1])
			{
				swap(&array[second], &array[second + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}
