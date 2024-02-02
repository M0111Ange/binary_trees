#include "binary_trees.h"

/**
 * check_subtree_Left - this checks if all nodes in left are smaller than
 * the root specified
 * @node: node in the tree to verify condition
 * @max: value to compare
 * Return: 1 if all nodes are smaller or equal or 0 otherwise
 */

int check_subtree_Left(const binary_tree_t *node, int max)
{
	int lt = 0, rt = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		lt = check_subtree_Left(node->left, max);
		rt = check_subtree_Left(node->right, max);
		if (lt == rt && lt == 1)
			return (1);
		return (0);
	}
}
/**
 * check_subtree_Right - this checks if all the nodes are bigger than the
 * specified root
 * @node: node in the tree to check
 * @min: value to compare
 * Return: 1 if all is bigger or equal or 0 otherwise
 */

int check_subtree_Right(const binary_tree_t *node, int min)
{
	int lt = 0, rt = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		lt = check_subtree_Right(node->left, min);
		rt = check_subtree_Right(node->right, min);
		if (lt == rt && lt == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - says if a tree is a valid Binary Search Tree
 * this process involves verifying that the left node is smaller than the root
 * then verify if the right node is bigger than the root.
 * after that verify if the left subtree has nodes smaller than root
 * and the right subtree has bigger nodes than root
 * @tree: the tree to access
 * Return: 1 if a BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int vari = 0, lt = 2, rt = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		vari = check_subtree_Left(tree->left, tree->n);
		if (vari == 0)
			return (0);
		lt = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		vari = check_subtree_Right(tree->right, tree->n);
		if (vari == 0)
			return (0);
		rt = binary_tree_is_bst(tree->right);
	}
	if (lt != 2 || rt != 2)
	{
		if (lt == 0 || rt == 0)
			return (0);
	}
	return (1);
}
