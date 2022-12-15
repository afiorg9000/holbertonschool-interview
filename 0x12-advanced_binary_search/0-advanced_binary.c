#include "search_algos.h"

/**
 * print_array - Function that print the array
 * @array: pointer to inicial parameter
 * @low: size_t type is firts parameter
 * @size: size_t type is de size of the array
 *
 * Return: void
 */

void print_array(int *array, size_t low, size_t size)
{
	size_t i;

	if (low == size)
		return;
	printf("Searching in array: ");
	for (i = low; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * binary_search - binary search
 * @arr: pointer the array
 * @left: type size_t firts parameter
 * @right: type size_t size
 * @x: integer for the search
 *
 * Return: integer indicated the index
 */

int binary_search(int *arr, size_t left, size_t right, int x)
{
	int mid;

	print_array(arr, left, right  + 1);
	if (right >= left)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == x && arr[mid - 1] != x)
			return (mid);
		if (arr[mid] == x && arr[mid - 1] == x)
			return (binary_search(arr, left, mid - 1, x));
		if (arr[mid] > x)
			return (binary_search(arr, left, mid - 1, x));
		return (binary_search(arr, mid + 1, right, x));
	}
	return (-1);
}

/**
 * advanced_binary - Function that find parameter
 * @array: array to search
 * @size: size of the array
 * @value: integer indicated the value to search
 *
 * Return: integer and is the index
 */

int advanced_binary(int *array, size_t size, int value)
{
	int i = 0;

	if (array == NULL || size < 1 || value < 0)
		return (-1);

	i = binary_search(array, 0, size - 1, value);
	return (i);
}
