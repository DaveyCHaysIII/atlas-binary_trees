#include "binary_trees.h"


int is_empty(queue_t *q);
const binary_tree_t *dequeue(queue_t *q);
void enqueue(queue_t *q, const binary_tree_t *node);
queue_t *create_queue(void);

/**
 * binary_tree_levelorder - prints the level order of a binary tree
 * @tree: the tree in question
 * @func: the function pointer
 *
 * Return: no return
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	queue_t *q;
	const binary_tree_t *current;

	if (!tree || !func)
		return;

	q = create_queue();
	enqueue(q, tree);

	while (!is_empty(q))
	{
		current = dequeue(q);
		func(current->n);

		enqueue(q, current->left);
		enqueue(q, current->right);
	}
	free(q);
}


/**
 * create_queue - create a queue
 *
 * Return: the queue
 */

queue_t *create_queue(void)
{
	queue_t *q;

	q = malloc(sizeof(queue_t));
	q->front = q->rear = NULL;
	return (q);
}

/**
 * enqueue - enqueue's a thing
 * @q: the queue
 * @node: the binary tree node to enqueue
 *
 * Return: no return
 */

void enqueue(queue_t *q, const binary_tree_t *node)
{

	queue_node_t *new_node;

	if (!node)
		return;
	new_node = malloc(sizeof(queue_node_t));
	new_node->node = node;
	new_node->next = NULL;

	if (!q->rear)
		q->front = q->rear = new_node;
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
}

/**
 * dequeue - dequeue's a thing
 * @q: the queue in question
 *
 * Return: a new binary_tree_t
 */

const binary_tree_t *dequeue(queue_t *q)
{

	queue_node_t *temp;
	const binary_tree_t *node;

	if (!q->front)
		return (NULL);
	temp = q->front;
	node = temp->node;
	q->front = q->front->next;

	if (!q->front)
		q->rear = NULL;

	free(temp);
	return (node);
}

/**
 * is_empty - determines if a queue is empty
 * @q: the queue in queuestion (hah!)
 *
 * return: 0 or 1, whichever is true/false
 */

int is_empty(queue_t *q)
{
	return (q->front == NULL);
}
