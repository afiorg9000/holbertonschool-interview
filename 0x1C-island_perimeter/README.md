# Island Perimeter

This Python program calculates the perimeter of an island described in a grid. The grid is a list of lists of integers, where 0 represents water and 1 represents land. Each cell is square, with a side length of 1. Cells are connected horizontally/vertically (not diagonally). The grid is rectangular, with its width and height not exceeding 100. The grid is completely surrounded by water, and there is only one island (or nothing). The island doesn't have "lakes" (water inside that isn't connected to the water surrounding the island).

## Usage

```python
#!/usr/bin/python3
"""
0-main
"""
island_perimeter = __import__('0-island_perimeter').island_perimeter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))
