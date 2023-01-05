#include "binary_trees.h"

/**
 * heap_extract - extracts the root of a heap
 * @root: pointer to the root of the heap
 *
 * Return: the value of the root
 */

int heap_extract(heap_t **root)
{
	int data, tmp_data;
	heap_t *del_leaf = NULL;
	heap_t *last_leaf = NULL;

	if (*root == NULL)
		return (0);

	data = (*root)->n;

	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		del_leaf = *root;
		*root = NULL;
		free(del_leaf);
		return (data);
	}
	last_leaf = sort_values(root);
	del_leaf = find_last_leaf(root);

	if (last_leaf == del_leaf)
	{
		if (del_leaf->parent->left == del_leaf)
			del_leaf->parent->left = NULL;
		else if (del_leaf->parent->right == del_leaf)
			del_leaf->parent->right = NULL;
		free(del_leaf);
	}
	else
	{
		tmp_data = del_leaf->n;
		last_leaf->n = tmp_data;
		if (del_leaf->parent->left == del_leaf)
			del_leaf->parent->left = NULL;
		else if (del_leaf->parent->right == del_leaf)
			del_leaf->parent->right = NULL;
		free(del_leaf);
	}
	return (data);
}

/**
 * sort_values - sorts the values of a heap
 *
 * @root: pointer to the root of the heap
 * Return: void
 */

heap_t *sort_values(heap_t **root)
{
	heap_t *tmp;
	int value;

	tmp = *root;

	if (tmp->left != NULL && tmp->right != NULL)
	{
		if (tmp->left->n >= tmp->right->n)
		{
			value = tmp->left->n;
			tmp->left->n = tmp->n;
			tmp->n = value;
			return (sort_values(&tmp->left));
		}
		else
		{
			value = tmp->right->n;
			tmp->right->n = tmp->n;
			tmp->n = value;
			return (sort_values(&tmp->right));
		}
	}
	else if (tmp->left != NULL && tmp->right == NULL)
	{
		value = tmp->left->n;
		tmp->left->n = tmp->n;
		tmp->n = value;
		return (tmp->left);
	}
	return (tmp);
}


/**
 * find_last_leaf - finds the last leaf of a heap
 *@root: pointer to the root of the heap
 *
 * Return: void
 */

heap_t *find_last_leaf(heap_t **root)
{
	heap_t *tmp;
	size_t lenght_right, lenght_left;

	tmp = *root;

	if (tmp->left != NULL && tmp->right != NULL)
	{
		lenght_right = binary_tree_height(&tmp->right);
		lenght_left = binary_tree_height(&tmp->left);

		if (lenght_left > lenght_right)
			return (find_last_leaf(&tmp->left));
		else
			return (find_last_leaf(&tmp->right));
	}
	else if (tmp->left != NULL && tmp->right == NULL)
		return (tmp->left);
	return (tmp);
}


/**
 * binary_tree_height - finds the length of a binary tree
 * @root: pointer to the root of the tree
 *
 * Return: the length of the tree
 */

size_t binary_tree_height(heap_t **root)
{
	size_t height_left = 0;
	size_t height_right = 0;
	heap_t *tmp;

	tmp = *root;
	if (tmp->left != NULL)
	{
		height_left = binary_tree_height(&tmp->left) + 1;
	}
	if (tmp->right != NULL)
	{
		height_right = binary_tree_height(&tmp->right) + 1;
	}
	if (height_left >= height_right)
		return (height_left);
	else
		return (height_right);
}