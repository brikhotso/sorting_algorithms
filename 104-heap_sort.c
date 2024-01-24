#include "sort.h"

/**
 * sift_down - Performs the sift-down operation in the heap.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @start: The index from where to start the sift-down.
 * @end: The last index of the heap.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child, swap, temp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
		{
			return;
		}
	}
}

/**
 * heapify - Builds a max heap from an array.
 * @array: The array to be transformed into a heap.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	size_t start = (size - 2) / 2;

	while (start < size)
	{
		sift_down(array, size, start, size - 1);
		if (start > 0)
			start--;
		else
			break;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);

	for (end = size - 1; end > 0; --end)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);

		sift_down(array, size, 0, end - 1);
	}
}
