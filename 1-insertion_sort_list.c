#include "sort.h"

/**
 * swap_nodes - swap nodes by comparing current node to a list of nodes
 * @list: list of nodes to sort
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (*list == NULL || node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - sorts one node at a time by comparing current node to
 * a list
 *
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insert_node = current->prev;

		while (insert_node != NULL && insert_node->n > current->n)
		{
			swap_nodes(list, insert_node, current);
			print_list(*list);
			insert_node = current->prev;
		}

		current = current->next;
	}
}
