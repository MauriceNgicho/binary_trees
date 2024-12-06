#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	size_t front = 0, rear = 0, size = 1024;
	int seen_null = 0;

	if (!tree)
		return (0);

	/* Allocate memory for the queue */
	queue = malloc(sizeof(*queue) * size);
	if (!queue)
		return (0);

	/* Start with the root node in the queue */
	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (current)
		{
			if (seen_null)
			{
				/* If a non-NULL node is found after a NULL, tree is not complete */
				free(queue);
				return (0);
			}
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
		else
		{
			/* NULL node encountered */
			seen_null = 1;
		}
	}

	free(queue);
	return (1);
}
