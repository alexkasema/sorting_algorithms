#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 *	the Bubble sort algorithm.
 * @array: Pointer to array to be sorted.
 * @size: size of the array.
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	int tmp, flag;
	size_t i, j;

	if (array == NULL || size <= 0)
		return;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = 1;
				print_array(array, size);
			}
		}

		if (!flag)
			return;
	}
}
