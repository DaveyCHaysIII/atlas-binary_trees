#include "binary_trees.h"


/**
 * binary_tree_is_leaf()- finds if a node is a leaf
 * @node: the node in question
 *
 * Return: 1 if yes, 0 if no
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left != NULL || node->right != NULL)
	{
		return (0);
	}
	return (1);
}
