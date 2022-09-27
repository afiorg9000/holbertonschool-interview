#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome.
 * @n: the number to be checked.
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
    unsigned long rev = 0, temp;

    temp = n;
    while (n != 0)
    {
		rev = rev * 10 + (temp % 10);
		temp /= 10;
    }

    if (n == rev)
        return 1;
    else
        return 0;
}