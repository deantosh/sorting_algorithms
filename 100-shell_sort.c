/*
 * Author: Deantosh Daiddoh & Natnael Tewodros
 * File: 100-shell_sort.c
 */

#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *		knuth sequence.
 * @array: the unsorted array
 * @size: the size of the array
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, gap = 0, aux = 0;
	int swap_flag;

	if (!array || size < 2)
		return;

	/*calculate gap to use for sorting*/
	while (gap < (int)size)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/*swap flag -- false*/
		swap_flag = 0;

		for (i = gap; i < (int)size; i++)
		{
			aux = array[i];
			for (j = i; j >= gap && array[j - gap] > aux;
						j -= gap)
			{
				if (array[j - gap] != array[j])
					array[j] = array[j - gap];
			}
			if (array[j] != aux)
				array[j] = aux;

			/*swap value -- true*/
			swap_flag = 1;
		}
		if (swap_flag)
			print_array(array, size);
		gap = (gap - 1) / 3; /*change the gap*/
	}
}
