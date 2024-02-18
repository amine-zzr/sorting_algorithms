#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using bubble sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, flag;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0; /* this will improve efficiency */
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
