#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array containing elements to swap.
 * @item1: Index of the first element.
 * @item2: Index of the second element.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - Implements the Hoare partition scheme for quicksort.
 * @array: The array to partition.
 * @first: The index of the first element in the current partition.
 * @last: The index of the last element in the current partition.
 * @size: The total size of the array (used for printing).
 *
 * Return: The index of the last element sorted.
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * qs - Recursive implementation of the quicksort algorithm.
 * @array: The array to sort.
 * @first: The index of the first element in the current partition.
 * @last: The index of the last element in the current partition.
 * @size: The total size of the array (used for printing).
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - Prepares and executes the quicksort algorithm
 * using Hoare's partition scheme.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
