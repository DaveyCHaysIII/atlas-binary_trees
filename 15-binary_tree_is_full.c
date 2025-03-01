#include "binary_trees.h"

/**
 * binary_tree_is_full()- finds if a binary tree is full
 * @tree: the tree in question
 *
 * Return: 1 for full, 0 for not
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int result = 0;
	if (!tree)
		return (0);

	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_full(tree->left) &&
			(binary_tree_is_full(tree->right);
}
