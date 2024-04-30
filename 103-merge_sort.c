#include "sort.h"

/**
 * merge - Merges two subarrays of array[].
 * @array: Array to be sorted
 * @left: Left subarray
 * @right: Right subarray
 * @left_count: Number of elements in left subarray
 * @right_count: Number of elements in right subarray
 *
 * Description: Merges two subarrays of array[]. First subarray is array[l..m]
 * Second subarray is array[m+1..r]
 */
void merge(int *array, int *left, int *right, int left_count, int right_count)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < left_count && j < right_count)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < left_count)
		array[k++] = left[i++];
	while (j < right_count)
		array[k++] = right[j++];
}

/**
 * merge_sort - Sorts an array in ascending order
 * @array: Array to be sorted
 * @size: Number of elements in the array
 *
 * Description: Sorts an array in ascending order
 */
void merge_sort(int *array, size_t size)
{
	int mid;
	int i;
	int *left;
	int *right;

	if (size < 2)
		return;

	mid = size / 2;

	left = (int *) malloc(mid * sizeof(int));
	right = (int *) malloc((size - mid) * sizeof(int));

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, mid, size - mid);

	free(left);
	free(right);
}

