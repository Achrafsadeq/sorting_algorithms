#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;

		/* Move temp node backward until we find its correct position */
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Store the previous node */
			prev_node = temp->prev;

			/* Update next pointer of the previous node */
			prev_node->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = prev_node;

			/* Move temp before prev_node */
			temp->next = prev_node;
			temp->prev = prev_node->prev;

			/* Update the previous node's prev pointer */
			prev_node->prev = temp;

			/* Update the prev's prev node's next pointer if it exists */
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;  /* If temp is now the first node */

			print_list(*list);
		}
	}
}
