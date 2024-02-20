#include "sort.h"
/**
 * shell_sort - this function defines the shell sort algorithm
 * @array: the array of unsorted data to be sorted
 * @size: the size of the array
 * Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t halved = 1, gap_itr, insert, i;
	int hold;

	while (halved < size)
		halved = halved * 3 + 1;

	while (halved > 0)
	{
		i = halved;
		halved = (halved - 1) / 3;
		for (gap_itr = halved; gap_itr < size; gap_itr++)
		{
			hold = array[gap_itr];
			for (insert = gap_itr; insert >= halved &&
								   array[insert - halved] > hold;
				 insert -= halved)
				array[insert] = array[insert - halved];
			array[insert] = hold;
		}
		if (i > halved - 1)
			print_array(array, size);
	}
}
