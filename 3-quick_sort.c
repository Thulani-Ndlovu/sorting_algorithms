#include "sort.h"

/**
* swap_helper - swaps two integers
* @num1: integer 1
* @num2: integer 2
*/

void swap_helper(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
* Lomuto_Partition - partitions the array by using the largest
* element as the pivot
* @array: array to be partitioned
* @Low: smaller number
* @High: bigger number
* @size: array size
* Return: pivot
*/

int Lomuto_Partition(int *array, int Low, int High, size_t size)
{
	int pivot = array[High];
	int s_index =  Low - 1, i = Low;

	while (i <= (High - 1))
	{
		if (array[i] < pivot)
		{
			s_index++;
			swap_helper(&array[s_index], &array[i]);
		}
		i++;
	}
	swap_helper(&array[s_index + 1], &array[High]);
	print_array(array,size);

	return (s_index + 1);
}
/**
* L_Sorting - sort an array of integers in ascending order
* @array: array to be sorted
* @Low: left most
* @High: Right most
* @size: array size
*/

void L_Sorting(int *array, int Low, int High, size_t size)
{
	int partit_index;

	if (Low < High)
	{
		partit_index = Lomuto_Partition(array, Low, High, size);
		L_Sorting(array, Low, partit_index - 1, size);
		L_Sorting(array, partit_index + 1, High, size);
	}
}

/**
* quick_sort - sorts array in ascending order using quick sort
* @array: array to be sorted
* @size: size of array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	L_Sorting(array, 0, size - 1, size);
}
