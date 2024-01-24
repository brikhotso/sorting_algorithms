#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: array of elements to sort
 * @size: lenght of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* Initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/*Shell Sort with decreasing gaps */
	while (gap > 0)
	{
		for (i = gap; i < size; ++i)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = tmp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
