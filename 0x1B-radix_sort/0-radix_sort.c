#include "sort.h"

/**
 * radix_sort - Sort an array of integers in ascending order
 * using the LSD radix sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 **/
void radix_sort(int *array, size_t size)
{
	int i, j;
	int *count, *temp;
	int max = array[0];
	int exp = 1;
	if (array == NULL || size < 2)
		return;
	count = malloc(sizeof(int) * 10);
	if (count == NULL)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		free(count);
		return;
	}
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max / exp > 0)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = (int)size - 1; i >= 0; i--)
		{
			j = (array[i] / exp) % 10;
			temp[count[j] - 1] = array[i];
			count[j]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = temp[i];
		print_array(array, size);
		exp *= 10;
	}
	free(count);
	free(temp);
}
