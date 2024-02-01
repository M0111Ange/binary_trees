#include "binary_trees.h"
/**
 * binary_tree_insert_left - add a node to the left of a parent node
 * and if it exists, move it down one level and add the new node first
 * @parent: parent of the node
 * @value: value of the node
 * Return: NULL if fail or the new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_n = binary_tree_node(parent, value);
	if (new_n == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		new_n->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_n;
	return (new_n);
}
