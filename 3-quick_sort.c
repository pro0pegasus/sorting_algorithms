#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integ in arr.
 * @a: first integ to swap.
 * @b: second integ to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order subset of arr of integ according to
 *                    lomuto parti scheme (last elem as pivot).
 * @array: array of integ.
 * @size: size of array.
 * @left: starting ind of subset to order.
 * @right: ending ind of subset to order.
 * Return: final parti ind.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implem quicksort algo through recursion.
 * @array: arr of integ to sort.
 * @size: size of  arr.
 * @left: start ind of arr parti to order.
 * @right: end ind of arr parti to order.
 * Description: Use Lomuto parti scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort arr of integ in ascending
 *              order using quicksort algo.
 * @array: array of integ.
 * @size: size of array.
 * Description: Use Lomuto parti scheme. Print
 *              arr after each swap of two elem.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
