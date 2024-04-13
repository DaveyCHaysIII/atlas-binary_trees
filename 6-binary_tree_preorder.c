#include "binary_trees.h"

/**
 * binary_tree_preorder()- navigates a tree preorder
 * @tree: the tree in question
 * @func: the function to perform on tree
 *
 * Return: No! No return! Return is no!
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		if (tree->left)
			binary_tree_preorder(tree->left, func);
		if (tree->right)
			binary_tree_preorder(tree->right, func);
	}
}
