#include "binary_trees.h"

/**
 * binary_tree_insert_left()- inserts a new node on the left of parent
 * @parent: the parent in question
 * @value: the value of n for the new node
 *
 * Return: pointer to new node or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (new_node);
	}
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new_node;

	return (new_node);
}
