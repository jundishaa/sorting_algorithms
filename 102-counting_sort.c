#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 *
 * Description: This function sorts an array of integers in ascending
 * order using the Counting sort algorithm. The counting array is printed
 * once it is set up.
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0, *count, *sorted;

	if (!array || size < 2)
		return;

	/* Find the maximum number in the array */
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	/* Initialize the count array */
	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Count the occurrence of each number in the array */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;


	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	/* Sort the numbers using the count array */
	sorted = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted array to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}

