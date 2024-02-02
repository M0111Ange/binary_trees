#include "binary_trees.h"
/**
 * bst_insert - the func inserts nodes in order to create a BST tree
 * @tree: tree to create with type BST
 * @value: node value to insert
 * Return: BST tree
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nw, *tempo;
	binary_tree_t *auxi;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		auxi = binary_tree_node((binary_tree_t *)(*tree), value);
		nw = (bst_t *)auxi;
		*tree = nw;
	}
	else
	{
		tempo = *tree;
		if (value < tempo->n)
		{
			if (tempo->left)
				nw = bst_insert(&tempo->left, value);
			else
			{
				auxi = binary_tree_node((binary_tree_t *)tempo, value);
				nw = tempo->left = (bst_t *)auxi;
			}
		}
		else if (value > tempo->n)
		{
			if (tempo->right)
				nw = bst_insert(&tempo->right, value);
			else
			{
				auxi = binary_tree_node((binary_tree_t *)tempo, value);
				nw = tempo->right = auxi;
			}
		}
		else
			return (NULL);
	}
	return (nw);
}
