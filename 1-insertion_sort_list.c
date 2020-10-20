#include "sort.h"

/**
 * insertion_sort_list - uses insertion sort algorithm to sort list
 * @list: list to sort
 *
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || *list == NULL)
		return;

	node = *list;
	node = node->next;

	while (node)
	{
		listint_t *back = node;

		while (back->prev)
		{
			if (back->n < back->prev->n)
			{
				swap_nodes(&back->prev, &back);
				while ((*list)->prev)
					*list = (*list)->prev;
				print_list(*list);
				continue;
			}
			back = back->prev;
		}
		node = node->next;
	}
}

/**
 * swap_nodes - swaps the position of two nodes
 * @ptr1: first node to swap
 * @ptr2: second node to swap
 * Return: no return
 */
void swap_nodes(listint_t **ptr1, listint_t **ptr2)
{
	listint_t *temp1, *node1, *node2;

	node1 = *ptr1;
	node2 = *ptr2;

	temp1 = node1->prev;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = temp1;

	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev != NULL)
		node2->prev->next = node2;
}
