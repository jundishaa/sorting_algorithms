#include "sort.h"
/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: Pointer to the array
 * @start: Index to start the sifting down operation
 * @end: Index to end the sifting down operation
 * @size: Number of elements in @array
 *
 * Return: No Return
 */

void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;
	int temp;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			temp = array[root];
			array[root] = array[child];
			array[child] = temp;
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - Create a heap from an array
 * @array: Pointer to the array
 * @size: Number of elements in @array
 *
 * Return: No Return
 */

void heapify(int *array, size_t size)
{
	ssize_t start;

	start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order
 * @array: Pointer to the array
 * @size: Number of elements in @array
 *
 * Return: No Return
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

