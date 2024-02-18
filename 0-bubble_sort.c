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
	int flag;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0; /* this will improve efficiency */
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

/**
 * swap - Swaps the values of two integers
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 *
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
