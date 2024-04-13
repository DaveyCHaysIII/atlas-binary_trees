#include "binary_trees.h"

/**
 * binary_tree_postorder()- navigates a tree postorder
 * @tree: the tree in question
 * @func: the function to perform on tree
 *
 * Return: How about no, Scott?
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		if (tree->left)
			binary_tree_postorder(tree->left, func);
		if (tree->right)
			binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
