#include "sort.h"

/**
 * bitonic_merge - Merges two halves of an array in the desired order.
 * @array: The array to be merged.
 * @size: The size of the array.
 * @up: Flag to indicate whether the merging is in increasing order.
 */
void bitonic_merge(int *array, size_t size, int up)
{
	size_t i, half;
	int temp;
    if (size > 1)
    {
        half = size / 2;

        for (i = 0; i < half; ++i)
        {
            if ((array[i] > array[i + half]) == up)
            {
                temp = array[i];
                array[i] = array[i + half];
                array[i + half] = temp;
            }
        }

	printf("Merging [%lu/%lu] (%s):\n", size, size * 2, up ? "UP" : "DOWN");
        print_array(array, size * 2);
	
        bitonic_merge(array, half, up);
        bitonic_merge(array + half, half, up);
    }
}

/**
 * bitonic_sort - Sorts an array of integers using Bitonic Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t half = size / 2;

        printf("Merging [%lu/%lu] (UP):\n", half, size);
        print_array(array, size);

        bitonic_sort(array, half);
        bitonic_sort(array + half, half);

        bitonic_merge(array, size, 1);
    }
}
