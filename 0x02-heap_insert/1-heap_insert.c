#include "binary_trees.h"

/**
 * binary_tree_size - measure the size of a binary tree from a given node
 * @tree: root node of tree to measure from
 * Return: size of tree from a given node
 */
size_t binary_tree_size(heap_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	else
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @num: number of nodes
 * Return: 1 if is perfect, otherwise 0
 */
int binary_tree_is_perfect(int num)
{
	num = num + 1;
	while (num % 2 == 0)
		num = num / 2;

	if (num == 1)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_levelorder - binary tree node in level order
 * @root: parent node
 * @node: node to be inserted
 * Return: pointer to the root
 */
heap_t *binary_tree_levelorder(heap_t *root, heap_t *node)
{
	size_t right, left;

	if (root == NULL)
	{
		root = node;
		node->parent = root;
		return (node);
	}

	right = binary_tree_size(root->right);
	left = binary_tree_size(root->left);

	if (right == 0 && left == 0)
	{
		root->left = node;
		node->parent = root;
		return (root);
	}
	else if (right == 0 && left == 1)
	{
		root->right = node;
		node->parent = root;
		return (root);
	}
	else if (right == left)
		root->left = binary_tree_levelorder(root->left, node);
	else if (right < left)
	{
		if (binary_tree_is_perfect(left))
			root->right = binary_tree_levelorder(root->right, node);
		else
			root->left = binary_tree_levelorder(root->left, node);
	}
	return (root);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap:
 *
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int swap;

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	*root = binary_tree_levelorder(*root, new_node);

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = swap;
		new_node = new_node->parent;
	}
	return (new_node);
}
