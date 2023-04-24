#!/usr/bin/python3


def isWinner(x, nums):
    def isPrime(num):
        if num < 2:
            return False
        for i in range(2, int(num**0.5)+1):
            if num % i == 0:
                return False
        return True

    def playGame(n):
        primes = [num for num in range(2, n+1) if isPrime(num)]
        numMoves = 0
        while True:
            if numMoves % 2 == 0:
                player = "Maria"
            else:
                player = "Ben"
            if not primes:
                return player
            for prime in primes:
                if n % prime == 0:
                    primes.remove(prime)
            numMoves += 1

    mariaWins = 0
    benWins = 0
    for i in range(x):
        result = playGame(nums[i])
        if result == "Maria":
            mariaWins += 1
        elif result == "Ben":
            benWins += 1

    if mariaWins > benWins:
        return "Maria"
    elif benWins > mariaWins:
        return "Ben"
    else:
        return None
