#include "binary_trees.h"

/**
 * binary_tree_insert_right()- inserts a new node on the right of parent
 * @parent: the parent in question
 * @value: the value of n for the new node
 *
 * Return: pointer to new node or NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}

