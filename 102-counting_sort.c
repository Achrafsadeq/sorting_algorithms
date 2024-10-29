#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Get the maximum value in an array
 * @array: Array to find max value from
 * @size: Size of the array
 * Return: Maximum value in array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * initialize_count_array - Initializes and allocates memory for count array
 * @max: Maximum value in array
 * Return: Pointer to the count array or NULL on failure
 */
int *initialize_count_array(int max)
{
	int *count = malloc(sizeof(int) * (max + 1));

	if (!count)
		return (NULL);

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	return (count);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int max = get_max(array, size);
	int *count = initialize_count_array(max);

	if (!count)
		return;

	/* Store count of each element */
	for (size_t j = 0; j < size; j++)
		count[array[j]]++;

	/* Modify count array to store actual positions */
	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1); /* Print the counting array */

	/* Allocate memory for output array */
	int *output = malloc(sizeof(int) * size);

	if (!output)
	{
		free(count);
		return;
	}
	/* Build the output array */
	for (size_t j = size - 1; j < size; j--)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}

	/* Copy output array to original array */
	for (size_t j = 0; j < size; j++)
		array[j] = output[j];

	free(count);
	free(output);
}
