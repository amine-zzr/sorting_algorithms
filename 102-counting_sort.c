#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using counting sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, j, mx = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
		if (mx < (size_t)array[i])
			mx = array[i];
	count = malloc(sizeof(int) * (mx + 1));
	output = malloc(sizeof(int) * (size + 1));
	if (!count || !output)
		return;
	for (i = 0; i < mx + 1; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		j = array[i];
		count[j] = count[j] + 1;
	}
	for (i = 1; i <= mx; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, mx + 1);
	for (i = size - 1; ; i--)
	{
		j = array[i];
		count[j] = count[j] - 1;
		output[count[j]] = array[i];
		if (i == 0)
			break;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
