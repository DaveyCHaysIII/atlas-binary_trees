#include "binary_trees.h"
#include "10-binary_tree_depth.c"

/**
 * binary_trees_ancestor - gets common ancestor of two nodes
 * @first: the first node
 * @second: the second node
 *
 * Return: lowest common ancestor node (LCA) or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (depth_first > depth_second)
		return (binary_trees_ancestor(first->parent, second));
	else if (depth_first < depth_second)
		return (binary_trees_ancestor(first, second->parent));
	else if (depth_first == depth_second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		if (first->parent == second->parent)
			return ((binary_tree_t *)first->parent);
		else
			return (binary_trees_ancestor(first->parent,
						second->parent));
	}
}
