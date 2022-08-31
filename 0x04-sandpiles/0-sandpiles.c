#include "sandpiles.h"

/**
 *  grid_check - checkes whether the grid is 3x3
 *  @grid: grid
 *  Return: 1 is the grid is valid, 0 if not
 */
int grid_check(int grid[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * grid_print - Prints the grid
 * @grid: The grid to print
 */
void grid_print(int grid[3][3])
{
	int i = 0, j = 0;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d", grid[i][j]);
			if (j < 2)
				putchar(' ');
		}
		putchar('\n');
	}
}


/**
 * grid_add - add 2 grids
 * @grid1: first grid
 * @grid2: second grid
 */

void grid_add(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}
/**
 * topple_grid - Takes care of the toppling that would occur
 * @grid: The grid in where the toppling is occurring
 * @toppleLocations: Specifically where the toppling is occurring
 */

void grid_topple(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int gridx[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			gridx[i][j] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1) >= 0 && (i - 1) < 3)
					gridx[i - 1][j] += 1;
				if ((j - 1) >= 0 && (j - 1) < 3)
					gridx[i][j - 1] += 1;
				if ((i + 1) >= 0 && (i + 1) < 3)
					gridx[i + 1][j] += 1;
				if ((j + 1) >= 0 && (j + 1) < 3)
					gridx[i][j + 1] += 1;
			}
		}
	}
	grid_add(grid1, gridx);
}

/**
  * sandpiles_sum - function that computes the sum of two sandpiles
  * @grid1: 2D array
  * @grid2: 2D array
  */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_add(grid1, grid2);
	while (!grid_check(grid1))
	{
		grid_print(grid1);
		grid_topple(grid1);
	}
}