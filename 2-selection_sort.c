#include "sort.h"

/**
* selection_sort - sorts an array in ascending order
* @array: array to be sorted
* @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smallest, s_index;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (smallest > array[j])
			{
				smallest = array[j];
				s_index = j;
			}
		}
		array[s_index] = array[i];
		array[i] = smallest;
		print_array(array, size);
	}
}
