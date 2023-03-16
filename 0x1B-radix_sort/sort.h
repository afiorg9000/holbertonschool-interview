#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void sort_radix_split(int *array, size_t size, int unist, int idx);

#endif
