#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to access
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt = 0;
	size_t rt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lt = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((lt > rt) ? lt : rt);
		}
}

/**
 * sub_avl - compares each subtree if its AVL.
 * @tree: node that point to the tree to check.
 * @high: pointer to the higher node selected
 * @lower: pointer to the lower node selected.
 * Return: 1 if tree is AVL, 0 otherwise.
 */

int sub_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t height_lt, height_rt, bal;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		height_lt = binary_tree_height(tree->left);
		height_rt = binary_tree_height(tree->right);
		bal = height_lt > height_rt ? height_lt - height_rt : height_rt - height_lt;
		if (bal > 1)
		{
			return (0);
		}
		return (sub_avl(tree->left, lower, tree->n - 1) &&
			sub_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - this func checks if a binary tree is a valid AVL tree.
 * @tree: tree to check.
 * Return: 1 if tree is AVL, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (sub_avl(tree, INT_MIN, INT_MAX));
}
