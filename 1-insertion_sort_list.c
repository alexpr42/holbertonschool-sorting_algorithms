#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *insertion_point = current->prev;
		listint_t *next_node = current->next;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point = insertion_point->prev;
		}
		if (insertion_point == NULL)
		{
			if (current->prev != NULL)
				current->prev->next = next_node;
			if (next_node != NULL)
				next_node->prev = current->prev;
			current->prev = NULL;
			current->next = *list;
			(*list)->prev = current;
			*list = current;
		}
		else if (insertion_point->next != current)
		{
			if (current->prev != NULL)
				current->prev->next = next_node;
			if (next_node != NULL)
				next_node->prev = current->prev;
			current->prev = insertion_point;
			current->next = insertion_point->next;
			if (insertion_point->next != NULL)
				insertion_point->next->prev = current;
			insertion_point->next = current;
		}
		print_list(*list);
		current = next_node;
	}
}
