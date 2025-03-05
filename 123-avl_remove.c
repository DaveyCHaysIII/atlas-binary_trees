#include "binary_trees.h"

avl_t *in_order_successor(avl_t *node);
avl_t *avl_search(const avl_t *tree, int value);
avl_t *rotate_d(avl_t *tree, int value);

/**
 * avl_remove - removes a node from an avl tree
 * @root: the root of the tree
 * @value: the value to find
 *
 * Return: pointer to new root node
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *successor, *node, *parent, *child;

	if (!root)
		return (NULL);
	node = avl_search(root, value);
	if (!node)
		return (root);
	parent = node->parent;
	if (!node->left && !node->right)
	{
		if (parent)
		{
			if (parent->left == node)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL;
		free(node);
	}
	else if (!node->left || !node->right)
	{
		child = (node->left) ? node->left : node->right;
		if (!parent)
			root = child;
		else if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
		child->parent = parent;
		free(node);
	}
	else
	{
		successor = in_order_successor(node);
		node->n = successor->n;
		avl_remove(node->right, successor->n);
	}
	while (parent)
	{
		root = rotate_d(parent, value);
		parent = parent->parent;
	}
	return (root);
}

/**
 * in_order_successor - finds the in order successor of node
 * @node: the root of the subtree to look through
 *
 * Return: the pointer to the node
 */

avl_t *in_order_successor(avl_t *node)
{
	avl_t *successor, *parent;

	if (node == NULL)
		return (NULL);

	if (node->right != NULL)
	{
		successor = node->right;
		while (successor->left != NULL)
			successor = successor->left;
		return (successor);
	}

	parent = node->parent;
	while (parent != NULL && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return (parent);
}


/**
 * avl_search - search a binary search tree for a value
 * @tree: the tree to search
 * @value: the value to search for
 *
 * Return: the node or NULL
 */

avl_t *avl_search(const avl_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((avl_t *)tree);

	if (value < tree->n)
		return (avl_search(tree->left, value));

	return (avl_search(tree->right, value));
}


/**
 * rotate_d - handles rotations of the avl
 * @tree: the tree in question
 * @value: the value being inserted into the tree
 *
 * Return: no return
 */

avl_t *rotate_d(avl_t *tree, int value)
{
	int balance;

	balance = binary_tree_balance(tree);

	if (balance > 1 && value < tree->left->n)
		return (binary_tree_rotate_right(tree));
	if (balance > 1 && value > tree->left->n)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && value > tree->right->n)
		return (binary_tree_rotate_left(tree));
	if (balance < -1 && value < tree->right->n)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}
