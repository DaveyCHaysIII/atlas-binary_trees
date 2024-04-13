#include "binary_trees.h"

/**
 * binary_tree_is_root()- finds if a node is the root
 * @node: the node in question
 *
 * Return: 1 if yes, 0 if no or NULL
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent != NULL)
	{
		return (0);
	}
	return (1);
}
