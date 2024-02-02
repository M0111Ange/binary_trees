#include "binary_trees.h"
/**
 * binary_tree_insert_right - add node to the right of parent node
 * if already exists, move it down one level and add the new node first
 * @parent: parent of the spec node
 * @value: value of the node
 * Return: NULL if fail or the new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		new_n->right = parent->right;
		parent->right->parent = new_n;
	}
	parent->right = new_n;
	return (new_n);
}
