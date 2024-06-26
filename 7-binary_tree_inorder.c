#include "binary_trees.h"

/**
 * binary_tree_inorder()- navigates a tree in order
 * @tree: the tree in question
 * @func: the function to perform on the tree
 *
 * Return: we don' need no stinkin' returns
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		if (tree->left)
			binary_tree_inorder(tree->left, func);

		func(tree->n);

		if (tree->right)
			binary_tree_inorder(tree->right, func);
	}
}
