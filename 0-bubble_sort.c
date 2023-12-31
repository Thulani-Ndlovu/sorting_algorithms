#include "sort.h"

/**
* bubble_sort - sorts array of integers in ascending order
* @array: array to be sorted
* @size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swaps = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swaps++;
				print_array(array, size);
			}
		}
		if (swaps == 0)
			return;

	}
}
