#include "binary_trees.h"

/**
 * binary_tree_is_root - Function that checks if a node is a root node
 * @node: Node to access
 * Return: 0 if its not a root or 1 if it is
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
