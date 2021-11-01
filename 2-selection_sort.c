#include "sort.h"

/**
 * selection_sort - Selection sort algorithm.
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	unsigned int min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array((const int *)array, size);
		}
	}
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
