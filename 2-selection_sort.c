#include "sort.h"

/**
 * selection_sort - sort elements byrepeatedly finding the minimum element from
 * the unsorted part of the array and putting it at the beginning.
 * @array: pointer to any array of elements to sort
 * @size: length of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		min = i;

		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
