#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm.
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;

	for (i = 0; i < size; i++)
	{
		flag = 1;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array((const int *)array, size);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
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
