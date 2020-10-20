#include "sort.h"

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - recursive function
 * @array: array to sort
 * @low: the lower end of section
 * @high: upper end of section
 * @size: size of the array
 * Return: no return
 */
void quicksort(int *array, unsigned int low, unsigned int high, size_t size)
{
	unsigned int p;

	if (low >= high)
		return;
	p = partition(array, low, high, size);
	if (p != 0)
		quicksort(array, low, p - 1, size);
	quicksort(array, p + 1, high, size);
}

/**
 * partition - breaks up array by partitioning it at certain index
 * @a: array to sort
 * @low: lower end of section
 * @high: upper end of section
 * @s: size of the array
 * Return: index of partition
 */
unsigned int partition(int *a, unsigned int low, unsigned int high, size_t s)
{
	unsigned int i, j;
	int pivot, temp;

	pivot = a[high];
	i = low;
	for (j = low; j <= high; j++)
	{
		if (a[j] < pivot)
		{
			if (a[j] != a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				print_array(a, s);
			}
			i++;
		}
	}
	if (a[i] != a[high])
	{
		temp = a[i];
		a[i] = a[high];
		a[high] = temp;
		print_array(a, s);
	}

	return (i);
}
