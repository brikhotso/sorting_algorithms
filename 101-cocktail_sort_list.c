#include "sort.h"

/**
 * swap_nodes_before - swaps two nodes before a forward pass in cocktail sort
 * @list: pointer to the head of the list
 * @tail: first node to swap
 * @shaker: second node to swap
 */
void swap_nodes_before(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * swap_nodes_after - swaps two nodes after a backward pass in cocktail sort
 * @list: pointer to the head of the list
 * @tail: first node to swap
 * @shaker: second node to swap
 */
void swap_nodes_after(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers using
 *                      the Cocktail Shaker sort algorithm
 * @list: Pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *shaker, *tail = NULL;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (shaker = *list; shaker && shaker->next; shaker =
			     shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_nodes_after(list, &tail, &shaker);
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (; shaker && shaker->prev; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_nodes_before(list, &tail, &shaker);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
