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
 * quick_sort - Sort by selecting pivot element and partition elements into two
 * subarrays based on thier relation to pivot element
 * @array: Array of elements to sort
 * @size: Length of array
 */
void quick_sort(int *array, size_t size)
{
	size_t len = size - 1;

	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, len, size);
}

/**
 * quicksort_recursive - Recursively sort partition of the array
 * @array: Pointer to the array of elements to sort
 * @low: Index of the first element of the partition
 * @high: Index of the last element of the partition
 * @size: Leghth of array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pivot - 1, size);
		quicksort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: Pointer to an array of elements to sort
 * @low: Index of the first element of the partition
 * @high: Index of the last element of the partition
 * @size: Lenght of array
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int *pivot, i, j;

	pivot = array + high;

	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i != j)
			{
				swap_elements(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap_elements(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}
