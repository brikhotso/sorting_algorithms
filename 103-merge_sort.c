#include "sort.h"

/**
 * merge - Merges two sub-arrays into a single sorted array.
 * @array: The original array containing the sub-arrays to be merged.
 * @temp: A temporary array to store the merged result.
 * @left: The starting index of the left sub-array.
 * @mid: The ending index of the left sub-array (midpoint).
 * @right: The ending index of the right sub-array.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(array + left, mid - left + 1);

	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	for (i = left, j = mid + 1, k = left; i <= mid && j <= right; ++k)
	{
		if (array[i] <= array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	printf("[Done]: ");
	print_array(temp + left, right - left + 1);

	for (i = left; i <= right; ++i)
		array[i] = temp[i];

}

/**
 * merge_sort_recursive - Recursively Merge Sort sub-array.
 * @array: The array to be sorted.
 * @temp: A temporary array to store intermediate results.
 * @left: The starting index of the sub-array to be sorted.
 * @right: The ending index of the sub-array to be sorted.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid + 1, right);

		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(size * sizeof(int));

	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);

	free(temp);
}
