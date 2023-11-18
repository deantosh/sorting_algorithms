/*
 * File: selection_sort.c
 * Author: Deantosh M Daiddoh & Natnael Tewodros
 */

#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *using the selection sort algorithm.
 * @array: the unsorted array
 * @size: the size of the array
 *
 * return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			/*swap values*/
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;

			/*print array*/
			print_array(array, size);
		}
	}
}
