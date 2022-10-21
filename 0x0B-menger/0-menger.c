#include "menger.h"
/**
 * menger - function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 * Return: If level is lower than 0, your function must do nothing
 */
void menger(int level)
{
	int row, column, the_level;

	if (level < 0)
		return;
	the_level = pow(3, level);
	for (row = 0; row < the_level; row++)
	{
		for (column = 0; column < the_level; column++)
			putchar(sponge(row, column));
		putchar('\n');
	}
}
/**
 * sponge - determines how many rows and columns to draw
 * @row: rows
 * @column: columns
 * Return: "#" or " "
 */
char sponge(int row, int column)
{
	while (row || column)
	{
		if (column % 3 == 1 && row % 3 == 1)
			return (' ');
		row = row / 3;
		column = column / 3;
	}
	return ('#');
}