#include "binary_trees.h"
/**
 * array_to_bst - func that turns an array to a BST tree
 * @array: array to convert
 * @size: array  size
 * Return: BST tree from array
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *new;

	new = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; i < size; i++)
	{
		if (i == 0)
		{
			bst_insert(&new, array[i]);
		}
		else
		{
			bst_insert(&new, array[i]);
		}
	}
	return (new);
}
