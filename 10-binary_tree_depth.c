#include "binary_trees.h"

/**
 * binary_tree_depth()- find the depth of a node
 * @tree: the node in question
 *
 * Return: depth of node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t i;
	binary_tree_t *tmp;

	if (!tree || !tree->parent)
	{
		return (0);
	}

	i = 1;
	tmp = tree;
	while (tmp->parent != NULL)
	{
		i++;
		tmp = tree->parent;
	}
	return (i);
}
