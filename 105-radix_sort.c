#include "sort.h"

/**
 * counting_sort_radix - Sorts an array of integers in ascending order
 * using counting sort modified to be used by radix sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 * @d: A integer multiple of 10 represent the digit we need to sort based on
 *
 */
static void counting_sort_radix(int *array, size_t size, long int d)
{
	int count[10];
	int *output;
	size_t i, j;

	output = malloc(sizeof(int) * (size + 1));
	for (i = 0; i < 10; i++)
		count[i] = 0;
	if (!output)
		return;
	for (i = 0; i < size; i++)
		count[(array[i] / d) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; ; i--)
	{
		j = (array[i] / d) % 10;
		count[j]--;
		output[count[j]] = array[i];
		if (i == 0)
			break;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using radix sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int mx;
	long int d;
	size_t i;

	if (array == NULL || size == 0)
		return;
	mx = 0;
	for (i = 0; i < size; i++)
		if (mx < array[i])
			mx = array[i];
	for (d = 1; (long int)mx / d > 0; d *= 10)
	{
		counting_sort_radix(array, size, d);
		print_array(array, size);
	}
}
