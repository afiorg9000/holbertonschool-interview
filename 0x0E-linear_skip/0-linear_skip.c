#include "search.h"
/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: pointer to the head of the skip list to search in
 * @value: he value to search for
 * Return: If value is not present in list or if head is NULL,
 * your function must return NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = list;

	if (list == NULL)
	{
		return (NULL);
    }
	while (list->n < value && list->express)
	{
		tmp = list;
		list = list->express;
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
	}

	if (value <= list->n)
		printf("Value found between indexes [%ld] and [%ld]\n",
				tmp->index, list->index);
	else
	{
		tmp = tmp->express;
		while (list->next)
			list = list->next;
		printf("Value found between indexes [%ld] and [%ld]\n",
				tmp->index, list->index);
	}

	while (tmp)
	{
		printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
		if (tmp->n == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
