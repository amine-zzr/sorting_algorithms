#include "sort.h"


/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 * the Quick sort algorithm with the Hoare partition scheme.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - Recursively sorts an array of integers using the Quick
 * sort algorithm with the Hoare partition scheme.
 * @array: The array to sort.
 * @start: The starting index of the partition to sort.
 * @end: The ending index of the partition to sort.
 * @size: The size of the array.
 */
void quicksort_hoare(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = hoare_partition(array, start, end, size);
		quicksort_hoare(array, start, pivot - 1, size);
		quicksort_hoare(array, pivot, end, size);
	}
}

/**
 * hoare_partition - Partitions an array using the Hoare scheme.
 * @array: The array to partition.
 * @start: The starting index of the partition.
 * @end: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The final position of the pivot element.
 */
int hoare_partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1, j = end + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (i);
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
