#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with Knuth sequence
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval *= 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > tmp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = tmp;
		}

		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
