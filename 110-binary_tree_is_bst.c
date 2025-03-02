#include "binary_trees.h"


void inorder(const binary_tree_t *tree,
		void (*func)(int, int *, int *), int *store, int *flag);
void check_sorted(int val, int *store, int *flag);

/**
 * binary_tree_is_bst - determines if a binary tree is a bst
 * @tree: the tree to check
 *
 * Return: no return
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int store, flag;

	if (!tree)
		return (0);

	store = 0;
	flag = 1;
	inorder(tree, check_sorted, &store, &flag);

	return (flag);
}

/**
 * inorder()- navigates a tree in order
 * @tree: the tree in question
 * @func: the function to perform on the tree
 * @store: the stored value of the previous tree->n
 * @flag: the 0-1 flag determening if the bst is a bst
 *
 * Return: we don' need no stinkin' returns
 */

void inorder(const binary_tree_t *tree,
		void (*func)(int, int *, int *), int *store, int *flag)
{
	if (tree && func)
	{
		if (*flag && tree->left)
			inorder(tree->left, func, store, flag);

		func(tree->n, store, flag);

		if (*flag && tree->right)
			inorder(tree->right, func, store, flag);
	}
}


/**
 * check_sorted - checks a value in a store
 * @val: the number to check
 * @store: the store
 * @flag: the 0-1 flag determening if the bst is a bst
 * Return: no return
 */

void check_sorted(int val, int *store, int *flag)
{
	if (val <= *store)
	{
		*flag = 0;
		return;
	}
	*store = val;
}
