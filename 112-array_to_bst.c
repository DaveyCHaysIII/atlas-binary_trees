#include "binary_trees.h"

/**
 * array_to_bst - turns an array to a bst
 * @array: the array in question
 * @size: the size of the array
 *
 * Return: the newly made bst
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t i;

	tree = NULL;
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);

	return (tree);
}
