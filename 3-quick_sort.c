#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort
 * quick_sort_recursive - declare low and high
 * lomuto_partition - use low and high
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i = low, j, pivot = array[high], temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (temp != array[i])
				print_array(array, size);

			++i;
		}
	}

	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	if (temp != array[i])
		print_array(array, size);

	return (i);
}
