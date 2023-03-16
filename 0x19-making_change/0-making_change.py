#!/usr/bin/python3
"""Return: fewest number of coins needed to meet total"""


def makeChange(coins, total):
    """Return: fewest number of coins needed to meet total"""
    if total <= 0:
        return 0
    # Initialize array with a value greater than total
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    # Iterate through all coin values
    for c in coins:
        # Update array for multiples of current coin value
        for i in range(c, total + 1):
            dp[i] = min(dp[i], dp[i - c] + 1)

    if dp[total] > total:
        return -1
    else:
        return dp[total]
