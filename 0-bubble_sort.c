/*
 * File: 0-bubble_sort.c
 * Author: Deantosh Daiddoh & Natnael Tewodros
 */

#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *bubble sort algorithm.
 * @array: the unsorted array
 * @size: the size of the array
 *
 * return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap_flag;

	/*if args are empty*/
	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/*reset the swap flag value*/
		swap_flag = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				/*set value if swapped*/
				swap_flag = 1;

				/*print the array*/
				print_array(array, size);
			}
		}
		if (!swap_flag)
			return;
	}
}
