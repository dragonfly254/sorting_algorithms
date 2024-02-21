#include "sort.h"

/**
 * swap - swaps two values.
 * @x: first value.
 * @y: second value.
 *
 * Return: none.
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto - calculates the partitioning index.
 * @array: array to be partitioned
 * @low: start index.
 * @high: end index.
 *
 * Return: partitioning index.
 */
size_t lomuto(int *array, size_t low, size_t high, size_t size)
{
	int pivot_value;
	size_t i, j;

	pivot_value = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_value)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);

}

/**
 * quick_sort_recursion - sorts recursively.
 * @array: input array.
 * @low: start idx.
 * @high: end idx.
 *
 * Return: none.
 */
void quick_sort_recursively(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto(array, low, high, size);

		if (pivot_idx > 0)
			quick_sort_recursively(array, low, pivot_idx - 1, size);
		if (pivot_idx < size - 1)
			quick_sort_recursively(array, pivot_idx + 1, high, size);

	}
}


/**
 * sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: input array.
 * @size: size of the array.
 *
 * Return: none.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursively(array, 0, size - 1, size);

}
