#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if complete, 0 otherwise.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *queue[1024], *node;
	int front, rear, found_null;

	if (!tree)
		return (0);

	front = rear = found_null = 0;
	queue[rear++] = (bst_t *)tree;
	while (front < rear)
	{
		node = queue[front++];
		if (node)
		{
			if (found_null)
				return (0);
			queue[rear++] = node->left;
			queue[rear++] = node->right;
		}
		else
			found_null = 1;
	}
	return (1);
}

