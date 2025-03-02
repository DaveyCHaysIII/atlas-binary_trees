#include "binary_trees.h"

/**
 * bst_insert - insert a node into a BST
 * @tree: pointer to the head of a BST
 * @value: the value to add to the node
 *
 * Return: Pointer to created node or NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			return ((*tree)->left = new_node);
		}
		return (bst_insert(&(*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			return ((*tree)->right = new_node);
		}
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL);
}

