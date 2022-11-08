#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of 
 * the array to be converted
 * @size: the number of element in the array
 *
 * Return: Pointer to the new AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{

	avl_t *tree;
	size_t i;

	if (!array || !size)
		return (NULL);

	tree = malloc(sizeof(avl_t));

	if (!tree)
		return (NULL);

	tree->n = array[0];
	tree->parent = NULL;
	tree->left = NULL;
	tree->right = NULL;

	for (i = 1; i < size; i++)
	{
		insert_node(&tree, array[i]);
	}

	return (tree);
}

/**
 * insert_node - inserts a node in a binary tree.
 * @tree: Pointer to the node to insert
 * @value: Value to insert
 *
 * Return: If there is no node in the binary tree
 * or if there are no values to be inserted 
 * then it will return.
 */

void insert_node(avl_t **tree, int value)
{
	avl_t *new_node;
	avl_t *current;

	if (!tree || !*tree)
		return;

	current = *tree;
	new_node = malloc(sizeof(avl_t));

	if (!new_node)
		return;

	new_node->n = value;
	new_node->parent = current;
	new_node->left = NULL;
	new_node->right = NULL;

	if (current->left == NULL)
		current->left = new_node;
	else if (current->right == NULL)
		current->right = new_node;
	else if (current->left->left == NULL || current->left->right == NULL)
		insert_node(&current->left, value);
	else
		insert_node(&current->right, value);
}