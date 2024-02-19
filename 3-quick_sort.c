#include "sort.h"

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

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * partition - Partitions the array using Lomuto partition scheme
 * @array: Pointer to the array to be sorted
 * @start: Starting index of the partition
 * @end: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot after partitioning
 */
int partition(int *array, int start, int end, size_t size)
{
	int pIndex = start - 1;
	int pivot = array[end];
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			pIndex++;
			if (pIndex != i)
			{
				swap(&array[i], &array[pIndex]);
				print_array(array, size);
			}
		}
	}

	if (pIndex + 1 != end)
	{
		swap(&array[end], &array[pIndex + 1]);
		print_array(array, size);
	}
	return (pIndex + 1);
}


/**
 * quick_sort_recursive - Recursively sorts the array using
 * Quick sort algorithm
 * @array: Pointer to the array to be sorted
 * @start: Starting index of the partition
 * @end: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quick_sort_recursive(array, start, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, end, size);
	}
}
