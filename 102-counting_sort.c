#include "sort.h"

/**
 * get_max - Finds the maximum value in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: The maximum value in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sorts an array of integers using Counting Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	size_t max = get_max(array, size);
	int *count;

	if (array == NULL || size < 2)
		return;

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; ++i)
		count[i] = 0;

	for (i = 0; i < size; ++i)
		count[array[i]]++;

	print_array(count, max + 1);

	j = 0;
	for (i = 0; i <= max; ++i)
	{
		while (count[i] > 0)
		{
			array[j] = (int)i;
			j++;
			count[i]--;
		}
	}
	free(count);
}
