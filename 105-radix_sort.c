#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * get_max - A utility function to get maximum value in array[]
 * @array: array
 * @size: size of array
 * Return: max value in array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * count_sort - A function to do counting sort of array[] according to
 * the digit represented by exp.
 * @array: array
 * @size: size of array
 * @exp: digit place
 */
void count_sort(int *array, size_t size, int exp)
{
	int output[size];
	int i, count[10] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - main function to do Radix Sort
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{

	int max = get_max(array, size);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}

