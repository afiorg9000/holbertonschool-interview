#!/usr/bin/python3
"""program that solves the N queens problem."""
import sys

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    try:
        n = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        exit(1)
    if n < 4:
        print('N must be at least 4')
        exit(1)

    sol = []

    def sol_queens(row, n, sol):
        if (row == n):
            print(sol)
        else:
            for col in range(n):
                place = [row, col]
                if valid_place(sol, place):
                    sol.append(place)
                    sol_queens(row + 1, n, sol)
                    sol.remove(place)

    def valid_place(sol, place):
        for queen in sol:
            if queen[1] == place[1]:
                return False
            if (queen[0] + queen[1]) == (place[0] + place[1]):
                return False
            if (queen[0] - queen[1]) == (place[0] - place[1]):
                return False
        return True

    sol_queens(0, n, sol)
