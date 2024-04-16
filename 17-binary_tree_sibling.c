#include "binary_trees.h"

/**
 * binary_tree_sibling()- finds a node's sibling!
 * @node: the node in question
 *
 * Return: pointer to sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left && node->parent->right)
	{
		if (node->parent->left == node)
		{
			return (node->parent->right);
		}
		else
		{
			return (node->parent->left);
		}
	}
	return (NULL);
}
