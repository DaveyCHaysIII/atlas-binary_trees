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
		new_node = bst_insert(&(*tree)->left, value);
	else if (value > (*tree)->n)
		new_node = bst_insert(&(*tree)->right, value);
	else
		return (NULL);

	return (new_node);
}

