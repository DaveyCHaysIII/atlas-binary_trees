#include "binary_trees.h"
#include "113-bst_search.c"

bst_t *in_order_successor(bst_t *node);

/**
 * bst_remove - removes and frees a binary search tree node
 * @root: the root node
 * @value: the value to search for
 *
 * Return: new root node
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor, *node, *parent, *child;

	if (!root)
		return (NULL);
	node = bst_search(root, value);
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
		bst_remove(node->right, successor->n);
	}
	return (root);
}

/**
 * in_order_successor - finds the in order successor of node
 * @node: the root of the subtree to look through
 *
 * Return: the pointer to the node
 */

bst_t *in_order_successor(bst_t *node)
{
	bst_t *successor, *parent;

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
