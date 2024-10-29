#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two values in an array based on the specified order.
 * @arr: The array containing the values to swap.
 * @item1: Index of the first item.
 * @item2: Index of the second item.
 * @order: Sorting order; 1 for ascending, 0 for descending.
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}

/**
 * merge - Recursively sorts bitonic sequences in both ascending
 * and descending order.
 * @arr: The array containing the bitonic sequence.
 * @low: The starting index of the sequence.
 * @nelemnt: The number of elements in the sequence.
 * @order: Sorting order; 1 for ascending, 0 for descending.
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, i;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}

/**
 * bitonicsort - Implements the recursive bitonic sort algorithm.
 * @arr: The array to sort.
 * @low: The starting index of the current sequence.
 * @nelemnt: The number of elements in the current sequence.
 * @order: Sorting order; 1 for ascending, 0 for descending.
 * @size: The total size of the array.
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}

/**
 * bitonic_sort - Prepares and executes the bitonic sort algorithm on an array.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
