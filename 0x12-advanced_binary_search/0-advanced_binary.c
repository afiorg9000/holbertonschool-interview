#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t first, last;

	if (!array)
		return (-1);
	first = 0;
	last = size - 1;
	return (recursive_search(array, first, last, value));
}

/**
 * print_array - ...
 *
 * @array: ...
 * @first: ...
 * @last: ...
 */
void print_array(int *array, int first, int last)
{
	int i;

	printf("Searching in array: ");
	for (i = first; i < last; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * recursive_search - ...
 *
 * @array: ...
 * @first: ...
 * @last: ...
 * @value: ...
 * Return: ...
 */
int recursive_search(int *array, size_t first, size_t last, int value)
{
	size_t half;

	if (first < last)
	{
		half = first + (last - first) / 2;
		print_array(array, (int)first, (int)last);
		if (array[half] >= value)
			return (recursive_search(array, first, half, value));
		else
			return (recursive_search(array, half + 1, last, value));
		return ((int)(half));
	}
	if (array[first] == value)
		return (first);
	print_array(array, (int)first, (int)last);
	return (-1);
}
