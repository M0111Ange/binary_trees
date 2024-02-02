#include "binary_trees.h"

/**
 * binary_trees_ancestor - func finds the lowest common ancestor of two nodes
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *a, *b;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	a = first->parent;
	b = second->parent;
	if (a == NULL || first == a || (!a->parent && b))
	{
		return (binary_trees_ancestor(first, b));
	}
	else if (b == NULL || b == second || (!b->parent && a))
	{
		return (binary_trees_ancestor(a, second));
	}
	return (binary_trees_ancestor(a, b));
}
