#include "binary_trees.h"

/**
 * binary_tree_leaves()- counts the leaves of a tree
 * @tree: the tree in question
 *
 * Return: number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (numLeaves(tree));
}

/**
 * numLeaves()- recursive answer to binary_tree_leaves
 * @tree: the exact same as above
 *
 * Return: number of leaves
 */

size_t numLeaves(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	return (numLeaves(tree->left) + numLeaves(tree->right));
}
