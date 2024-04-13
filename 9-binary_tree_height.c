#include "binary_trees.h"

/**
 * binary_tree_height()- finds height of entire tree
 * @tree: the tree in question
 *
 * Return: size of tree or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_branch;
	size_t right_branch;

	left_branch = 0;
	right_branch = 0;

	if (!tree)
		return (0);

	if (tree->left)
	{
		left_branch = 1 + binary_tree_height(tree->left);
	}

	if (tree->right)
	{
		right_branch = 1 + binary_tree_height(tree->right);
	}

	if (left_branch < right_branch)
	{
		return (left_branch);
	}
	return (right_branch);
}
