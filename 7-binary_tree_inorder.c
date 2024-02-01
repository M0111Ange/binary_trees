#include "binary_trees.h"
/**
 * binary_tree_inorder - this func prints elements of tree using
 * in-order traversal
 * @tree: tree to access
 * @func: function to use
 * Return: void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
