#!/usr/bin/python3
"""that returns the perimeter of the island described in grid:"""


def island_perimeter(grid):
    perimeter = 0
    rows = len(grid)
    columns = len(grid[0])

    for i in range(rows):
        for j in range(columns):
            if grid[i][j] == 1:
                # Check the cell above
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1

                # Check the cell below
                if i == rows - 1 or grid[i + 1][j] == 0:
                    perimeter += 1

                # Check the cell to the left
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1

                # Check the cell to the right
                if j == columns - 1 or grid[i][j + 1] == 0:
                    perimeter += 1

    return perimeter
