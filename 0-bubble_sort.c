#include "sort.h"

/**
 * bubble_sort - uses bubble sort algorithm to sort array
 * @array: array to sort
 * @size: size of array
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	int swap = 1;

	while (swap)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i + 1];

				array[i + 1] = array[i];
				array[i] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
