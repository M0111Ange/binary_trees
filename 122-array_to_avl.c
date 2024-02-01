#include "binary_trees.h"

/**
 * array_to_avl - this func turns an array to a avl tree
 * @array: the array
 * @size: size of the array
 * Return: new AVL tree
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j = 0;
	avl_t *my_root;

	my_root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&my_root, array[i]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (my_root);
}
