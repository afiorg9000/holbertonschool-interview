#include "holberton.h"
#include <stdlib.h>

/**
 * _puts - prints a string.
 * @s: a string.
 * @l: length.
 * Return: Nothing.
 */
void _puts(char *s, int l)
{
	for (; l; l--, s++)
		if (*s)
			_putchar(*s);
	_putchar(0xA);
}

/**
 * is_digit - Identify if a string is a number
 * @str: String to identify
 *
 * Return: 1 is digit, otherwise 0 on failure
 */
char is_digit(char *str)
{
	if (*str && (*str < 48 || *str > 57))
		return (0);
	return (*str ? is_digit(str + 1) : 1);
}

/**
 * _strlen - Calculate the size of the string
 * @str: String to evaluate
 *
 * Return: String lenght
 */
int _strlen(char *str)
{
	return (*str ? _strlen(str + 1) + 1 : 0);
}

/**
 * multiplication - Create the multiplications of the strings
 * @num1: Number one
 * @num2: Number two
 *
 * Return: 1 if successful or 0 if failed
 */
int operations(char *num1, char *num2)
{
	int carry = 0, len1 = 0, len2 = 0, len = 0;
	char *result = NULL;

	len1 = _strlen(num1) - 1;
	len2 = _strlen(num2) - 1;
	len = len1 + len2 + 2;
	result = calloc(sizeof(char), (len + 1));
	if (!result)
	{
		_puts("Error", 48);
		return (0);
	}

	for (; num1[len1]; len1--)
	{
		for (carry = 0, len2 = _strlen(num2) - 1; num2[len2]; len2--)
		{
			carry += ((num2[len2] - '0') * (num1[len1] - '0'));
			carry += result[(len1 + len2) + 1] ?
			result[(len1 + len2) + 1] - '0' : result[(len1 + len2) + 1];
			result[(len1 + len2) + 1] = (carry % 10) + '0';
			carry /= 10;
		}
		if (carry != 0)
			result[(len1 + len2) + 1] += (carry + '0');
	}
	_puts(result, len);
	free(result);
	return (1);
}

/**
 * main - multiplies two positive numbers.
 * @ac: arguments count
 * @av: arguments value (num1, num2)
 * 
 * Description: Usage: mul num1 num2
 * Print the result, followed by a new line.
 * 
 * Return: 0 if success otherwise 98 and print Error.
 */
int main(int ac, char **av)
{
	(void) av;
	if (ac != 3 || !is_digit(av[1]) || !is_digit(av[2])
	|| !operations(av[1], av[2]))
	{
		_puts("Error", 5);
		exit(98);
	}
	return (0);
}