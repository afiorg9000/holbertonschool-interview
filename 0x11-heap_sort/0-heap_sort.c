#include "sort.h"

/**
 * heap_sort - max heap
 * @array: array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2 ; i > 0; i--)
		heap(array, size, i - 1, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heap(array, i, 0, size);
	}
}


/**
 * heap - gets max in root
 * @arr: array
 * @n: size array
 * @i: current position
 * @size: size
 */
void heap(int *arr, int n, int i, size_t size)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int max = i;
	if (left < n && arr[left] > arr[max])
		max = left;

	if (right < n && arr[right] > arr[max])
		max = right;

	if (max != i)
	{
		swap(&arr[i], &arr[max], arr, size);
		heap(arr, n, max, size);
	}
}

/**
 * swap - swap int
 * @a: first int
 * @b: second int
 * @array: array
 * @n: number
 */
void swap(int *a, int *b, int *array, size_t n)
{
int temp = *a;
*a = *b;
*b = temp;

print_array(array, n);
}
