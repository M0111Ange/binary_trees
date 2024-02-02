#include "binary_trees.h"
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: tree to search
 * @value: value to search
 * Return: the node with the value or NULL if the value is not in the tree
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *f;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		f = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		f = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (f);
}
