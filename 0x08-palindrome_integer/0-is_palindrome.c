#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome.
 * @n: the number to be checked.
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
unsigned long rev = 0, tmp = n;

while(tmp != 0)
{
rev = rev + (tmp % 10);
tmp = tmp / 10;
rev = rev * 10;
}
if ((rev / 10) == n)
{
return (1);
}
return (0);
}