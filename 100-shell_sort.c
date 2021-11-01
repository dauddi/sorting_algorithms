#include "sort.h"

/**
 * shell_sort - Insert sort algorithm
 * @array: pointer to array
 * @size: Size of the array
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j = 0;
	int value;

	if (array == NULL)
		return;
	while (gap * 3 + 1 < size)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{

		for (i = gap; i < size; i++)
		{
			value = array[i];
			j = i;
			while (j > gap - 1 && array[j - gap] >= value)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = value;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
