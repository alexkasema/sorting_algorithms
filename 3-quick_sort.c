#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *	Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Returns: Void.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_array(array, 0, size - 1, size);
}

/**
 * partition_array - splits an array into partitions.
 * @array: Array to partition.
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: The index of the pivot element after partitioning
 */

int partition_array(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = low;
	int tmp = 0;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_array - Array to be sorted by partitioning.
 * @array: Array to be sorted.
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Returns: void
 */

void quick_sort_array(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition_array(array, low, high, size);

		quick_sort_array(array, low, pivot - 1, size);
		quick_sort_array(array, pivot + 1, high, size);
	}
}
