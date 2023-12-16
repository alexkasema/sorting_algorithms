#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 *	the Selection sort algorithm
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Returns: Nothing
 */

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, smallest_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		smallest_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_idx])
				smallest_idx = j;
		}
		if (smallest_idx != i)
		{
			tmp = array[i];
			array[i] = array[smallest_idx];
			array[smallest_idx] = tmp;
			print_array(array, size);
		}

	}
}
