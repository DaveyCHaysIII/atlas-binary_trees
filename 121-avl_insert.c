#include "binary_trees.h"

avl_t *rotate(avl_t *tree, int value);

/**
 * avl_insert - insert a node into an avl tree
 * @tree: the tree in question
 * @value: the value node->n
 *
 * Return: pointer to new node
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	new_node = NULL;
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			*tree = rotate(*tree, value);
			return ((*tree)->left = new_node);
		}
		return (avl_insert(&(*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			*tree = rotate(*tree, value);
			return ((*tree)->right = new_node);
		}
		return (avl_insert(&(*tree)->right, value));
	}

	*tree = rotate(*tree, value);

	return (new_node);
}

/**
 * rotate - handles rotations of the avl
 * @tree: the tree in question
 * @value: the value being inserted into the tree
 *
 * Return: no return
 */

avl_t *rotate(avl_t *tree, int value)
{
	int balance;

	balance = binary_tree_balance(tree);

	if (balance > 1 && value < tree->left->n)
		return (binary_tree_rotate_left(tree));
	if (balance > 1 && value > tree->left->n)
	{
		binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && value > tree->right->n)
		return (binary_tree_rotate_right(tree));
	if (balance < -1 && value < tree->right->n)
	{
		binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}
