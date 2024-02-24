#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}

/**
 * merge_sort_recursive - Recursively sorts a subarray of integers using the
 * merge sort algorithm.
 * @array: Pointer to the array containing the subarray to be sorted.
 * @buffer: Temporary buffer used during the merging process.
 * @start: Index of the first element of the subarray.
 * @end: Index of the last element of the subarray + 1.
 */
void merge_sort_recursive(int *array, int *buffer, size_t start, size_t end)
{
	size_t mid;

	if (start < end - 1)
	{
		mid = start + (end - start) / 2;

		merge_sort_recursive(array, buffer, start, mid);
		merge_sort_recursive(array, buffer, mid, end);

		merge(array, buffer, start, mid, end);
	}
}

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: Pointer to the array containing the subarrays to be merged.
 * @buffer: Temporary buffer used during the merging process.
 * @start: Index of the first element of the left subarray.
 * @mid: Index of the first element of the right subarray.
 * @end: Index of the last element of the right subarray + 1.
 */
void merge(int *array, int *buffer, size_t start, size_t mid, size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
		buffer[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		buffer[k++] = array[i];
	for (; j < end; j++)
		buffer[k++] = array[j];
	for (i = start, k = 0; i < end; i++)
		array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
