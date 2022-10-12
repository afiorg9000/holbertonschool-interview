#include "slide_line.h"

/**
* right_slider - slides right
* @line: Pointer
* @size: size of array
* Return: 1 upon success, or 0 upon failure 
*/
int right_slider(int *line, int size)
{
	int i, j, x = 0, temp;

	temp = line[size - 1];
	for (i = size - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (line[j] != 0)
			{
				if (temp == line[j])
				{
					temp = temp + line[j];
					line[j] = 0;
					break;
				}
				else if (temp == 0)
				{
					temp = line[j];
					line[i] = temp;
					line[j] = 0;
				}
				else
				{
					temp = line[i];
					x = 1;
					break;
				}
			}
		}
		line[i] = temp;
		if (x == 1)
		{
			temp = line[i - 1];
			x = 0;
		}
		else
			temp = 0;
	}
	return (1);
}

/**
 * move_left - slides left
 * @line: Pointer
 * @size: size of array
 * Return: 1 upon success, or 0 upon failure  
*/
int left_slider(int *line, int size)
{
	int i, j;
	int temp = line[0], x = 0;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (line[j] != 0)
			{
				if (temp == line[j])
				{
					temp = temp + line[j];
					line[j] = 0;
					break;
				}
				else if (temp == 0)
				{
					temp = line[j];
					line[i] = temp;
					line[j] = 0;
				}
				else
				{
					temp = line[i];
					x = 1;
					break;
				}
			}
		}
		line[i] = temp;
		if (x == 1)
		{
			temp = line[i + 1];
			x = 0;
		}
		else
			temp = 0;
	}
	return (1);
}

/**
* slide_line -hat slides and merges an array of integers 
* @line: pointer
* @size: size of the array
* @direction: left or right
* Return: 1 upon success, or 0 upon failure 
*/
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);
	if (direction == SLIDE_LEFT)
		return (left_slider(line, (int)size));
	if (direction == SLIDE_RIGHT)
		return (right_slider(line, (int)size));
	return (0);
}
