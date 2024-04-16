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
	if (tree->left)
		result = result + binary_tree_is_full(tree->left);
	if (tree->right)
		result = result + binary_tree_is_full(tree->right);
	if ((tree->left && tree->right) || (!tree->left && !tree->right))
	{
		result = 1;
		return (result);
	}
	else
	{
		return (result);
	}
}
