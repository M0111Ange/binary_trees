i#include "binary_trees.h"
/**
 * binary_tree_is_leaf - checks if its a node is a leaf node; node without
 * children nodes
 * @node: node to check
 * Return: 1 if it is a leafnode or 0 if it`s not
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
