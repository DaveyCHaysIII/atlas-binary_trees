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
	parent->left = (binary_tree_node(parent, value));
	if (parent->left == NULL)
	{
		return (NULL);
	}
	return (parent->left);
}
