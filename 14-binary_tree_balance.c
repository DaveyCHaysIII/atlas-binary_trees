#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_balance()- gives the balance factor of a tree
 * @tree: the tree in question
 *
 * Return: the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int l, r;

	l = 0;
	r = 0;
	if (!tree)
		return 0;
	if (tree->left)
		l = binary_tree_height(tree->left) + 1;
	if (tree->right)
		r = binary_tree_height(tree->right) + 1;

	return ((l - r));

}
