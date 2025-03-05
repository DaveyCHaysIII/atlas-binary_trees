#include "binary_trees.h"


avl_t *sarr_to_avl_func(int *array, int start, int end, avl_t *parent);

/**
 * sorted_array_to_avl - make an avl with no rotations from sorted array
 * @array: the array in question
 * @size: the size of the array
 *
 * Return: pointer to root or NULL
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);

	return (sarr_to_avl_func(array, 0, ((int)size) - 1, NULL));
}

/**
 * sarr_to_avl_func - actually does all the work for the wrapper func
 * @array: the array
 * @start: the starting point
 * @end: the ending point
 * @parent: the parent node
 *
 * Return: the root node of the avl tree
 *
 */

avl_t *sarr_to_avl_func(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);

	root->left = sarr_to_avl_func(array, start, mid - 1, root);
	root->right = sarr_to_avl_func(array, mid + 1, end, root);

	return (root);

}
