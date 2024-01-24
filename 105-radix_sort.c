#include "sort.h"

/**
 * get_max - Finds the maximum value in an array.
 * @array: The array to find the maximum value.
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
 * rad_counting_sort - Performs counting sort on the specified digit.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current digit place value.
 */
void rad_counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; ++i)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; --i)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; ++i)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using Radix Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		rad_counting_sort(array, size, exp);
		print_array(array, size);
	}
}
