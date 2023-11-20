/*
 * Author: Deantosh Daiddoh & Natnael Tewodros
 * File: 3-quick_sort.c
 */

#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using lomuto
 *		partition scheme.
 * @array: the unsorted array
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	/*initial values*/
	low = 0;
	high = size - 1;

	/*call the recursive function to sort array*/
	quick_sort_r(array, size, low, high);
}

/**
 * quick_sort_r - This is the quick sort recursive function used to
 *			partition and sort the array.
 * @array: the unsorted array
 * @n: the size of the array
 * @low: the first index of the array to sort
 * @high: the last index of the array to sort
 *
 * Return: void.
 */
void quick_sort_r(int *array, size_t n, int low, int high)
{
	int pi;

	if (low < high)
	{
		/*divide the array into two sub arrays*/
		pi = lomuto_partition(array, n, low, high);

		/*sort the sub arrays*/
		quick_sort_r(array, n, low, pi - 1);
		quick_sort_r(array, n, pi + 1, high);
	}
}


/**
 * swap_values - Swaps two values in an array.
 * @a: the first value
 * @b: the second value
 *
 * Return: void
 */
void swap_values(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}


/**
 * lomuto_partition - Scheme to partition the array into two sub arrays
 *			based on the position of values against the pivot.
 *			in this scheme the pivot is the last item in the array.
 * @array: the unsorted array
 * @n: the size of the array
 * @low: the position of first array element
 * @high: the position of the last array element
 *
 * Return: pivot index.
 */
int lomuto_partition(int *array, size_t n, int low, int high)
{
	int pivot, i, idx;

	idx = low - 1;
	pivot = array[high];
	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			idx++;
			if (i != idx)
			{
				swap_values(&array[i], &array[idx]);
				print_array(array, n);
			}
		}
	}
	if ((idx + 1) != high)
	{
		swap_values(&array[idx + 1], &array[high]);
		print_array(array, n);
	}
	return (idx + 1);
}
