#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, pos = 0;
	int temp, target;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		target = array[i];
		pos = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < target)
			{
				target = array[j];
				pos = j;
			}
		}
		if (pos > 0)
		{
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
	}
}
