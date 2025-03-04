#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include "110-binary_tree_is_bst.c"

/**
 * binary_tree_is_avl - checks if a binary tree is an avl
 * @tree: the tree to check
 *
 * Return: 0 or 1
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (0);
	if (!binary_tree_is_bst(tree))
	{
		return (0);
	}
	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	if (tree->left && binary_tree_is_avl(tree->left) == 0)
		return (0);
	if (tree->right && binary_tree_is_avl(tree->right) == 0)
		return (0);
	return (1);

}
