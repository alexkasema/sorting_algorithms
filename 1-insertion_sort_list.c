#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: double pointer to the doubly linked list
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *current, *tmp;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		if (node->n < node->prev->n)
		{
			current = node;
			while (current->prev && current->n < current->prev->n)
			{
				tmp = current->prev;
				if (tmp->prev)
					tmp->prev->next = current;
				else
					*list = current;
				if (current->next)
					current->next->prev = tmp;
				tmp->next = current->next;
				current->prev = tmp->prev;
				tmp->prev = current;
				current->next = tmp;
				print_list(*list);
			}
		}
		node = node->next;
	}
}
