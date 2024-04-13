#include "binary_trees.h"
#include "11-binary_tree_size.c"
#include "12-binary_tree_leaves.c"

/**
 * binary_tree_nodes()- returns num nodes with at least 1 child
 * @tree: the tree in question
 *
 * Return: number of parent nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}
