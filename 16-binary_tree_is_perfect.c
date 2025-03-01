#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include "11-binary_tree_size.c"
#include <math.h>

/**
 * binary_tree_is_perfect()- determines if a binary tree is perfect
 * @tree: the tree in question
 *
 * Return: 1 for perfect, 0 for imperfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	if (!binary_tree_is_full(tree))
		return (0);
	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
		return (0);

	return (1);
}
