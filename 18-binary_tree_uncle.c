#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if no uncle exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;

	/* Check if the parent is the left child, return the right child */
	if (grandparent->left == parent)
		return (grandparent->right);

	/* If the parent is the right child, return the left child */
	if (grandparent->right == parent)
		return (grandparent->left);

	return (NULL);
}
