#include "binary_trees.h"

/**
 * balanciaga - func that Measures balance factor of a AVL
 * @tree: tree to check
 * Return: balanced factor
 */
void balanciaga(avl_t **tree)
{
	int bival;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balanciaga(&(*tree)->left);
	balanciaga(&(*tree)->right);
	bival = binary_tree_balance((const binary_tree_t *)*tree);
	if (bival > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bival < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor_node - get the next successor (the min node in the right subtree)
 * @node: tree to access
 * Return: the min value of tree
 */
int successor_node(bst_t *node)
{
	int lt = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		lt = successor_node(node->left);
		if (lt == 0)
		{
			return (node->n);
		}
		return (lt);
	}

}

/**
 * two_next - function that gets the next successor using the min
 * value in the right subtree, and then replace the node value for
 * this successor
 * @root: node tat has two children
 * Return: the value found
 */
int two_next(bst_t *root)
{
	int new_val = 0;

	new_val = successor_node(root->right);
	root->n = new_val;
	return (new_val);
}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_next(root));
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int t = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		t = remove_type(root);
		if (t != 0)
			bst_remove(root->right, t);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of tree
 * @value: value to remove
 * Return: the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *rooti = (avl_t *) bst_remove((bst_t *) root, value);

	if (rooti == NULL)
		return (NULL);
	balanciaga(&rooti);
	return (rooti);
}
