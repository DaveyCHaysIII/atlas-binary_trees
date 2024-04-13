#include "binary_trees.h"

/**
 * binary_tree_node()- creates a node for a binary tree!
 * @parent: the parent of the node
 * @value: value to store at node
 *
 * Return: pointer to the node, or NULL
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	if (*parent == NULL)
	{
		return (NULL);
	}

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (*new_node == NULL)
	{
		return (NULL);
	}

	new_node->parent = parent;
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
