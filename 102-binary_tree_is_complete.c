#include "binary_trees.h"
/**
 * newer_node - this Func creates a new_node in a linked_list
 * @node: Type pointer of node to be created
 * Return: the node created
 */
link_t *newer_node(binary_tree_t *node)
{
	link_t *new_node;

	new_node =  malloc(sizeof(link_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}
/**
 * free_node - this Function frees the nodes at the linked list
 * @head: Node of the linked_list
 * Return: void
 */

void free_node(link_t *head)
{
	link_t *tempo;

	while (head)
	{
		tempo = head->next;
		free(head);
		head = tempo;
	}
}
/**
 * node_push - this Function pushes a node into the stack
 * @node: pointer to node of the tree
 * @head: head node in the stack
 * @tail: tail node in the stack
 */
void node_push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *nw;

	nw = newer_node(node);
	if (nw == NULL)
	{
		free_node(head);
		exit(1);
	}
	(*tail)->next = nw;
	*tail = nw;
}
/**
 * pops - a Function that pops a node into the stack
 * @head: head node of in the stack
 */
void pops(link_t **head)
{
	link_t *tempo;

	tempo = (*head)->next;
	free(*head);
	*head = tempo;
}
/**
 * binary_tree_is_complete - this Function checks if a binary tree is complete
 * @tree: tree to access
 * Return: 1 if is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = newer_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_node(head);
				return (0);
			}
			node_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_node(head);
				return (0);
			}
			node_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pops(&head);
	}
	return (1);
}
