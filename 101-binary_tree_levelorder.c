#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	size_t front = 0, back = 0;

	if (!tree || !func)
	return;

	/* Allocate memory for the queue */
	queue = malloc(sizeof(*queue) * 1024);
	if (!queue)
		return;

	/* Enqueue root node */
	queue[back++] = tree;

	while (front < back) /* While queue is not empty */
	{
		const binary_tree_t *node = queue[front++]; /* Dequeue node */

		func(node->n); /* Process current node */

		/* Enqueue left child if it exists */
		if (node->left)
			queue[back++] = node->left;

		/* Enqueue right child if it exists */
		if (node->right)
			queue[back++] = node->right;
	}

	free(queue); /* Free allocated memory for the queue */
}
