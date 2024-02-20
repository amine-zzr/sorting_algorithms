#include "sort.h"


/**
 * swap_nodes - swap two nodes in a linked list
 * @node_1: node of a list
 * @node_2: node of a list
 *
 * Return: node to left which can be the new head if he has a null prev
 */
listint_t	*swap_nodes(listint_t *node_1, listint_t *node_2)
{
	listint_t *front, *back;

	front = node_2->next;
	back = node_1->prev;

	if (front)
		front->prev = node_1;
	node_1->next = front;
	node_1->prev = node_2;

	if (back)
		back->next = node_2;
	node_2->prev = back;
	node_2->next = node_1;
	return (node_2);
}

/**
 * insertion_sort_list - Sorts a List of integers in ascending order
 * using insertion sort
 * @list: Reference of list Pointer to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *less, *cur;

	if (!list || !*list)
		return;
	cur = *list;
	cur = cur->next;
	while (cur)
	{
		less = cur;
		cur = cur->next;
		while (less->prev && less->n < less->prev->n)
		{
			if (less->prev == *list)
				*list = swap_nodes(less->prev, less);
			else
				swap_nodes(less->prev, less);
			print_list(*list);
		}
	}
}
