#include "lists.h"

/**
 * is_palindrome - function in C that checks if a singly linked list is a palindrome.
 * @head: pointer to the beginning of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (1);
	return (valid(head, *head));
}

/**
 * Valid - to check if the list is palindrome
 * @head: pointer to the beginning of the list
 * @last: pointer to the end of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int valid(listint_t **head, listint_t *last)
{
	if (last == NULL)
		return (1);

	if (valid(head, last->next) && (*head)->n == last->n)
	{
		*head = (*head)->next;
		return (1);
	}
	return (0);
}
