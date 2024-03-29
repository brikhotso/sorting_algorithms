#include "sort.h"

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		   char flow);
void bitonic_sort(int *array, size_t size);

/**
 * bitonic_seq - Convert an array of integers into bitonic seq.
 * @array: The array to be merged.
 * @size: The size of the array.
 * @flow: Flag to indicate whether the merging is in increasing order.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);

		print_array(array + start, seq);
		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_merge - Merges two halves of an array in the desired order.
 * @array: The array to be merged.
 * @size: The size of the array.
 * @flow: Flag to indicate whether the merging is in increasing order.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t index, jump = seq / 2;
	int tmp, *arr1, *arr2;

	if (seq > 1)
	{
		for (index = start; index < start + jump; index++)
		{
			arr1 = array + index;
			arr2 = array + index + jump;
			if ((flow == UP && array[index] > array[index + jump])
			    || (flow == DOWN && array[index] <
				array[index + jump]))
			{
				tmp = *arr1;
				*arr1 = *arr2;
				*arr2 = tmp;
			}
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sort - Sorts an array of integers using Bitonic Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
