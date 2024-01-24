#include "sort.h"

/**
 * swap_elements - swaps two elements
 * @a: pointer to first element
 * @b: ponter to second element
 */
void swap_elements(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme
 * @array: Pointer to an array of elements to sort
 * @low: Index of the first element of the partition
 * @high: Index of the last element of the partition
 * @size: Length of array
 *
 * Return: Index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low + (high - low) / 2];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap_elements(array + i, array + j);
			print_array(array, size);
		}
		else
		{
			return (j);
		}
	}
}

/**
 * quicksort_hoare_recursive - Recursively sort partition of the array
 * @array: Pointer to the array of elements to sort
 * @low: Index of the first element of the partition
 * @high: Index of the last element of the partition
 * @size: Length of array
 */
void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);

		quicksort_hoare_recursive(array, low, pivot, size);
		quicksort_hoare_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sort by selecting pivot element and partition into two
 * subarrays based on their relation to pivot element
 * @array: Array of elements to sort
 * @size: Length of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare_recursive(array, 0, size - 1, size);
}
