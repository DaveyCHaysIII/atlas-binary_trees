#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree left
 * @tree: the tree(or subtree) in question
 *
 * Return: the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;
	binary_tree_t *new_root;
	binary_tree_t *parent;

	if (!tree)
		return (NULL);

	root = tree;
	new_root = root->right;
	parent = root->parent;
	root->right = new_root->left;
	new_root->left = root;

	if (root->right != NULL)
		root->right->parent = root;
	new_root->parent = parent;
	root->parent = new_root;

	if (parent != NULL)
	{
		if (parent->left == root)
			parent->left = new_root;
		else
			parent->right = new_root;
	}

	return (new_root);
}
