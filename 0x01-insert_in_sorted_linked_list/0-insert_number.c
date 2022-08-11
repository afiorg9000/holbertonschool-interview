#include "lists.h"
#include <stdlib.h>
/**
 * insert_node - Write a function in C that inserts a number into a sorted singly linked list.
 * @head: head of the list 
 * @number: number to add in the list
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
	listint_t *tmp, *tmp_next;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = new;
		new->n = number;
		return (new);
	}
	tmp = *head;
	tmp_next = tmp->next;

	if (tmp->n >= number)
	{
		new->next = tmp;
		new->n = number;
		*head = new;
		return (new);
	}

	while (tmp_next != NULL)
	{
		if (tmp->n <= number && tmp_next->n >= number)
		{
			tmp->next = new;
			new->next = tmp_next;
			new->n = number;
			return (new);
		}
		tmp = tmp->next;
		tmp_next = tmp_next->next;
	}
	tmp->next = new;
	new->n = number;
	return (new);
}
