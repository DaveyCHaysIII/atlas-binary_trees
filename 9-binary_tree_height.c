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

	if (!tree)
		return (0);

	left_branch = binary_tree_height(tree->left);
	right_branch = binary_tree_height(tree->right);

	return (1 + (left_branch > right branch ? left_branch : right_branch));
}
