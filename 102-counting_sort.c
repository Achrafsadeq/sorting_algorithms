#include "sort.h"
#include <stdlib.h>

/**
 * arr_max - Finds the maximum value in an array
 * @array: Pointer to the array
 * @size: Total number of elements in the array
 *
 * Return: The maximum integer value in the array
 */
int arr_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts an array using the Counting Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *sorted_arr, max_value, num;
	size_t i;

	if (size < 2 || !array)
		return;

	max_value = arr_max(array, size);
	count_arr = malloc(sizeof(int) * (max_value + 1));
	sorted_arr = malloc(sizeof(int) * size);

	for (i = 0; (int)i <= max_value; i++)
		count_arr[i] = 0;

	for (i = 0; i < size; i++)
		count_arr[array[i]] += 1;

	for (i = 1; (int)i <= max_value; i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, max_value + 1);

	for (i = 0; i < size; i++)
	{
		sorted_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_arr[i];

	free(sorted_arr);
	free(count_arr);
}
