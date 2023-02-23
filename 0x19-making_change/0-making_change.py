#!/usr/bin/python3
"""Return: fewest number of coins needed to meet total"""


def makeChange(coins, total):
    """Return: fewest number of coins needed to meet total"""
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        if coin <= total:
            count += total // coin
            total %= coin
    if total > 0:
        return -1
    return count
