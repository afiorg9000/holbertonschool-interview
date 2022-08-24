#!/usr/bin/python3
"""calculates the fewest number of operations"""


def minOperations(n):
    """calculates the fewest number of operations"""
    if n < 2:
        return 0
    operations = []
    number = 1
    while n != 1:
        number += 1
        if n % number == 0:
            while n % number == 0:
                n /= number
                operations.append(number)
    return sum(operations)
