/*
 * File: 1-insertion_sort_list.c
 * Author: Deantosh M Daiddoh & Natnael Tewodros
 */

#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *			order using the insertion sort algorithm
 * @list: the doubly linked list to sort
 *
 * return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		while (tmp && tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				/*swap nodes*/
				swap_nodes(tmp->prev, tmp);
				if (!tmp->prev)
					*list = tmp;
				/*print list*/
				print_list((const listint_t *)*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}


/**
 * swap_nodes - Swap nodes in a doubly linked list.
 * @n: the first node
 * @m: the second node
 *
 * return: void.
 */
void swap_nodes(listint_t *n, listint_t *m)
{
	listint_t *prev_node, *next_node;

	prev_node = n->prev;
	next_node = m->next;
	if (prev_node)
		prev_node->next = m;
	if (next_node)
		next_node->prev = n;
	n->next = next_node;
	n->prev = m;
	m->next = n;
	m->prev = prev_node;
}
