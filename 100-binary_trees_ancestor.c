#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if none found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *ancestor1, *ancestor2;

	if (!first || !second)
		return (NULL);

	ancestor1 = (binary_tree_t *)first;
	ancestor2 = (binary_tree_t *)second;

	/* Move up the tree until the two nodes meet */
	while (ancestor1 != ancestor2)
	{
		ancestor1 = ancestor1->parent ? ancestor1->parent : (binary_tree_t *)second;
		ancestor2 = ancestor2->parent ? ancestor2->parent : (binary_tree_t *)first;
	}

	return (ancestor1);
}
