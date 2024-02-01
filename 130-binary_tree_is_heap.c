#include "binary_trees.h"

/**
 * binary_tree_height - this Func measures the height of a binary tree
 * @tree: tree to access
 * Return: height of tree
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
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			lt = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lt > rt) ? lt : rt);
		}
}

/**
 * binary_tree_balance - Measures balance of a binary tree
 * @tree: tree to access
 * Return: balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int rt = 0, lt = 0, bal = 0;

	if (tree)
	{
		lt = ((int)binary_tree_height(tree->left));
		rt = ((int)binary_tree_height(tree->right));
		bal = lt - rt;
	}
	return (bal);
}

/**
 * tree_is_perfect - function accesses if a tree is perfect or not
 * @tree: tree to check
 * Return: 0 if is not a perfect or other number that is the level of height
 */

int tree_is_perfect(const binary_tree_t *tree)
{
	int lt = 0, rt = 0;

	if (tree->left && tree->right)
	{
		lt = 1 + tree_is_perfect(tree->left);
		rt = 1 + tree_is_perfect(tree->right);
		if (rt == l && rt != 0 && lt != 0)
			return (rt);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - perfect or not a tree
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int c = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		c = tree_is_perfect(tree);
		if (c != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: tree to look into
 * Return: 1 if it is, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bival;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	bival = binary_tree_balance(tree);
	if (bival == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (bival == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
