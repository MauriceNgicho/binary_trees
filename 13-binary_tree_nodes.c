#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: Number of nodes with at least 1 child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_count = 0;
	size_t right_count = 0;
	size_t total_count = 0;

	if (tree == NULL)
		return (0);

	/* Check if this node has at least one child */
	if (tree->left != NULL || tree->right != NULL)
		total_count = 1;

	/* Count nodes in the left and right subtrees */
	left_count = binary_tree_nodes(tree->left);
	right_count = binary_tree_nodes(tree->right);

	/* Add up the counts */
	total_count += left_count + right_count;

	return (total_count);
}
