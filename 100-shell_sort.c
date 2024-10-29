#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              Shell sort algorithm with Knuth sequence
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the maximum gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Start with the largest gap and reduce it until gap = 1 */
	while (gap > 0)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			/* Shift elements that are gap positions ahead if they're greater */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}

		/* Print array after each gap reduction */
		print_array(array, size);

		/* Calculate the next gap using Knuth sequence in reverse */
		gap = (gap - 1) / 3;
	}
}
