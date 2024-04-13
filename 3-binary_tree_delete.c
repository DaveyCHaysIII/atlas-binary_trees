#include "binary_trees.h"

/**
 * binary_tree_delete()- deletes a binary tree
 * @tree: the tree to delete
 *
 * Return: NEVER! NEVER EVER EVER!
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
