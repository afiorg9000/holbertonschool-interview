#include "binary_trees.h"
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
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);
	root = insert_sorted_array(array, 0, size - 1);
	return (root);
}

/**
 * binary_tree_node - creates a binary tree node
 * @parent: Parent node
 * @value: Value of node
 *	
 * Return: create new Binary tree
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
 * insert_sorted_array - inserts sorted array to a Binary Tree
 * @array: Pointer to first element of sorted array
 * @min: Minimum value
 * @max: Maximum Value
 *
 * Return: Pointer to root node of AVL Tree, or Null on failure
 */

avl_t *insert_sorted_array(int *array, int min, int max)
{
	int medium_value;
	avl_t *tree;
	binary_tree_t *parent = NULL;

	if (min > max)
		return (NULL);

	medium_value = (min + max) / 2;
	tree = binary_tree_node(parent, array[medium_value]);

	if (tree == NULL)
		return (NULL);

	tree->left = insert_sorted_array(array, min, medium_value - 1);
	tree->right = insert_sorted_array(array, medium_value + 1, max);

	if (tree->left)
		tree->left->parent = tree;

	if (tree->right)
		tree->right->parent = tree;
	return (tree);
}
