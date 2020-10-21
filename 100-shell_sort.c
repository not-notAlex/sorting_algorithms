#include "sort.h"

void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size)
		gap = gap * 3 + 1;
	gap /= 3;

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
