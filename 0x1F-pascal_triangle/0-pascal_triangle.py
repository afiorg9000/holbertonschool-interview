#!/usr/bin/python3
'''0. Pascal's Triangle'''


def pascal_triangle(n):
    '''A function thar returns a list of
    lists of integers representing the
    Pascal’s triangle of n'''
    if n <= 0:
        return []
    triangle = []
    for line in range(n):
        sub_triangle = []
        for column in range(line + 1):
            if column > 0:
                try:
                    row = triangle[
                        line - 1
                    ][column] + triangle[
                        line - 1
                    ][column - 1]
                except IndexError:
                    row = 1
            else:
                row = 1
            sub_triangle.append(row)
        triangle.append(sub_triangle)
    return triangle
