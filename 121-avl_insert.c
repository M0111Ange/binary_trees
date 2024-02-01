#include "binary_trees.h"

/**
 * insert_node - inserts node value in a AVL.
 * @tree: tree to access
 * @parent: parent node of struct AVL.
 * @new: type**pointer left or right insertion.
 * @in_val: value of the insertion.
 * Return: pointer to the new root, or NULL
 */

avl_t *insert_node(avl_t **tree, avl_t *parent, avl_t **new, int in_val)
{
	int bival;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, in_val));
	if ((*tree)->n > in_val)
	{
		(*tree)->left = insert_node(&(*tree)->left, *tree, new, in_val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < in_val)
	{
		(*tree)->right = insert_node(&(*tree)->right, *tree, new, in_val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	bival = binary_tree_balance(*tree);
	if (bival > 1 && (*tree)->left->n > in_val)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bival > 1 && (*tree)->left->n < in_val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bival < -1 && (*tree)->right->n < in_val)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bival < -1 && (*tree)->right->n > in_val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - inserts a value into an AVL tree.
 * @tree: the AVL tree to insert into.
 * @value: value to store in the node
 * Return: the inserted node, or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *in_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert_node(tree, *tree, &in_node, value);
	return (in_node);
}
