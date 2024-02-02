#include "binary_trees.h"
/**
 * exp_sort - func creates tree using the half element of the array
 * @parent: the parent of the node to create
 * @array: sorted array
 * @start: position where the array starts
 * @end: position where the array ends
 * Return: tree created
 */
avl_t *exp_sort(avl_t *parent, int *array, int start, int end)
{
	avl_t *root;
	binary_tree_t *tempo;
	int mid = 0;

	if (start <= end)
	{
		mid = (start + end) / 2;
		tempo = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (tempo == NULL)
			return (NULL);
		root = (avl_t *)tempo;
		root->left = exp_sort(root, array, start, mid - 1);
		root->right = exp_sort(root, array, mid + 1, end);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - creates the avl tree from sorted array
 * @array: sorted array
 * @size: size of this sorted array
 * Return: alv tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (exp_sort(NULL, array, 0, ((int)(size)) - 1));
}
