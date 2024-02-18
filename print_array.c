#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
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
