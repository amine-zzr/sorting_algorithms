#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index start
 * @array: Array to heapify
 * @start: Index of the root of the heap
 * @end: Last index of the heap
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t child, swap, root = start;
	int temp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		/* compares the current root with its left child */
		if (array[swap] < array[child])
			swap = child;

		/* checks if there's a right child and compares it */
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;

			print_array(array, size);

			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;
	/* Build max heap */
	for (i = size / 2; i > 0; i--)
		sift_down(array, i - 1, size - 1, size);

	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);

		sift_down(array, 0, i - 1, size);
	}
}
