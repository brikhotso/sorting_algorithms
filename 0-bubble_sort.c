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
 * bubble_sort - runs through a list of elements comparing current to next and
 * swaping as needed , process repeats until all elements are sorted
 *
 * @array: pointer to an array of elements to sort
 * @size: size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swapped;

	if (array == NULL || size < 2)
		return;

	do {
		swapped = 0;

		for (i = 0; i < size - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				swap_elements(&array[i], &array[i + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}

	} while (swapped);
}
