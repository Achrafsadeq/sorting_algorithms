#include "sort.h"
#include <stdlib.h>

/**
 * arr_max - Finds the maximum value in an array
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 * Return: The maximum integer value in the array
 */
int arr_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - Sorts an array using the Counting sort algorithm
 * @array: Pointer to the array of integers to sort
 * @size: Number of elements in the array
 *
 * This function sorts an array by counting occurrences of each value,
 * calculating cumulative counts, and using them to place each value
 * in its correct position in the sorted output.
 */
void counting_sort(int *array, size_t size)
{
	int *arr, *o_arr, max, num;
	size_t i;

	if (size < 2 || !array)
		return;

	max = arr_max(array, size);
	/* Allocate memory for counting array and output array */
	arr = malloc(sizeof(size_t) * (max + 1));
	o_arr = malloc(sizeof(int) * size);

	/* Initialize counting array to zero */
	for (i = 0; (int)i <= max; i++)
		arr[i] = 0;

	/* Count occurrences of each value */
	for (i = 0; i < size; i++)
	{
		num = array[i];
		arr[num] += 1;
	}
	/* Calculate cumulative counts */
	for (i = 1; (int)i <= max; i++)
		arr[i] += arr[i - 1];

	/* Print the counting array for debugging */
	print_array(arr, max + 1);

	/* Place each element in the sorted output array based on count */
	for (i = 0; i < size; i++)
	{
		o_arr[arr[array[i]] - 1] = array[i];
		arr[array[i]]--;
	}
	/* Copy sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = o_arr[i];
	/* Free allocated memory */
	free(o_arr);
	free(arr);
}
