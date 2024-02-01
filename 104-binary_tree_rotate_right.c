#include "binary_trees.h"

/**
 * binary_tree_rotate_right -this func rotates the binary tree right
 * @tree: The tree to access
 * Return: Pointer to new node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tempo;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	tempo = tree->left;
	tree->left = tempo->right;
	if (tempo->right != NULL)
	{
		tempo->right->parent = tree;
	}
	tempo->right = tree;
	tempo->parent = tree->parent;
	tree->parent = tempo;
	return (tempo);
}
