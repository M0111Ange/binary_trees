#include "binary_trees.h"
/**
 * binary_tree_height - this Func measures the height of a binary tree
 * @tree: tree to be measured
 * Return: the height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt = 0;
	size_t rt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lt = tree->left ? 1 + binary_tree_height(tree->left) : 0; 
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lt > rt) ? l : rt);
	}
}
/**
 * binary_tree_depth - depth of a specified node from root
 * @tree: node to be accessed
 * Return: 0 if node is root or node depth
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
 	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - this func makes a linked list from leve of depth and node
 * @head: pointer to head of linked list
 * @tree: tree to access
 * @level: depth of node to store
 * Return: void
 */

void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *tempo;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return;
	}
	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		tempo = *head;
		while (tempo->next != NULL)
		{
			tempo = tempo->next;
		}
		new->next = NULL;
		tempo->next = new;
	}
}

/**
 * recursion - goes through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: tree to access
 * Return: void
 */

void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t hlevel = 0;

	if (tree != NULL)
	{
		hlevel = binary_tree_depth(tree);
		linked_node(head, tree, hlevel);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - print the nodes element in a lever-order
 * @tree: tree to access
 * @func: function to use
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *tempo;
	size_t height = 0, counter = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (counter <= height)
		{
			tempo = head;
			while (tempo != NULL)
			{
				if (counter == tempo->n)
				{
					func(tempo->node->n);
				}
				tempo = tempo->next;
			}
			counter++;
		}
		while (head != NULL)
		{
			tempo = head;
			head = head->next;
			free(tempo);
		}
	}
}
