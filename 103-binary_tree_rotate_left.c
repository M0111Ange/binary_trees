#include "binary_trees.h"

/**
 * binary_tree_rotate_left - this Function rotates the binary tree to left
 * @tree: The binary tree root
 * Return: returns the Pointer node of the new node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newview;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	newview = tree->right;
	tree->right = newview->left;
	if (newview->left != NULL)
	{
		newview->left->parent = tree;
	}
	newview->left = tree;
	newview->parent = tree->parent;
	tree->parent = newview;
	return (newview);
}
