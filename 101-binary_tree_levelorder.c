#include "binary_trees.h"


int is_empty(queue_t *q);
const binary_tree_t *dequeue(queue_t *q)
void enqueue(queue_t *q, const binary_tree_t *node)
queue_t *create_queue(void)

/**
 *
 *
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	queue_t *q = create_queue();
	enqueue(q, tree);

	while (!is_empty(q))
	{
		const binary_tree_t *current = dequeue(q);
		func(current->value);

		enqueue(q, current->left);
		enqueue(q, current->right);
	}
	free(q);
}


/**
 *
 *
 */

queue_t *create_queue(void)
{
	queue_t *q = malloc(sizeof(queue_t));
	q->front = q->rear = NULL;
	return (q);

}

/**
 *
 *
 */

void enqueue(queue_t *q, const binary_tree_t *node)
{
	if (!node)
		return;

	queue_node_t *new_node = malloc(sizeof(queue_node_t));
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
 *
 *
 */

const binary_tree_t *dequeue(queue_t *q)
{
	if (!q->front)
		return (NULL);

	queue_node_t *temp = q->front;
	const binary_tree_t *node = temp_node;
	q->front = q->front->next;

	if (!q->front)
		q->rear = NULL;

	free(temp);
	return (node);
}

/**
 *
 *
 */

int is_empty(queue_t *q)
{
	return q->front == NULL;
}
