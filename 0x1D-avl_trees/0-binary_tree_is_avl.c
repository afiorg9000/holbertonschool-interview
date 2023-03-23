#include "binary_trees.h"

#define ABS(x) ((x) > 0 ? (x) : (-(x)))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 *
 * Properties of an AVL Tree:
 * An AVL Tree is a BST
 * The difference between heights of left and right subtrees cannot be more
 * than one
 * The left and right subtree each must also be a binary search tree
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);

	return (avl_check(tree, INT_MIN, INT_MAX, &height));
}

/**
 * avl_check - recursively checks if tree is AVL
 *
 * @tree: pointer to current root
 * @height: height pointer of this tree
 * @min: actual minimun value
 * @max: actual maximun value
 *
 * Return: if is AVL 1, else 0
 */
int avl_check(const binary_tree_t *tree, int min, int max, int *height)
{
	int h1 = 0, h2 = 0;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (!avl_check(tree->left, min, tree->n, &h1) ||
	    !avl_check(tree->right, tree->n, max, &h2))
		return (0);

	*height = MAX(h1, h2) + 1;

	return (ABS(h1 - h2) <= 1);
}