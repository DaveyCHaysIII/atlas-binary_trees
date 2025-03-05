#include "binary_trees.h"

/**
 * array_to_avl - converts an array to an avl
 * @array: the array in question
 * @size: the size of the array
 *
 * Return: pointer to root node of avl or NULL;
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t i;

	if (!array || !size)
		return (NULL);

	tree = NULL;
	for (i = 0; i < size; i++)
	{
		avl_insert(&tree, array[i]);
	}
	return (tree);
}
