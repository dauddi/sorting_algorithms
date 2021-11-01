#include "sort.h"

/**
 * lomuto_part - lomuto partition algorithm.
 * @array: array of integers
 * @size: size of the array
 * @hi: last value
 * @lo: first value
 * Return: i + 1.
 */
int lomuto_part(int *array, int lo, int hi, size_t size)
{
	int i;

	for (i = lo - 1, lo; lo <= hi - 1; lo++)
	{
		if (array[lo] < array[hi])
		{
			i = i + 1;
			if (i != lo)
			{
				swap(&array[lo], &array[i]);
				print_array((const int *)array, size);
			}
		}
	}
	if (array[i + 1] > array[hi])
	{
		swap(&array[i + 1], &array[hi]);
		print_array((const int *)array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_easy - recurtion algorithm.
 * @array: array of integers
 * @size: size of the array
 * @hi: last value
 * @lo: first value
 * Return: Nothing.
 */
void quick_sort_easy(int *array, int lo, int hi, size_t size)
{
	int pi;

	if (lo < hi)
	{
		pi = lomuto_part(array, lo, hi, size);
		quick_sort_easy(array, lo, pi - 1, size);
		quick_sort_easy(array, pi + 1, hi, size);
	}
}

/**
 * quick_sort - Quick sort algorithm.
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	size_t lo, hi;

	hi = size - 1;
	lo = 0;
	quick_sort_easy(array, lo, hi, size);
}

/**
 * swap - swap function.
 * @a: pointer to array in position a
 * @b: pointer to array in position b
 * Return: Nothing.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
