#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: input doubly linked list.
 *
 * Return: none
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = NULL;

	if (*list == NULL || (*list)->next == NULL)
		return;

	cur = (*(list))->next;

	while (cur != NULL)
	{
		listint_t *tmp = cur->prev;
		
		while (tmp != NULL && tmp->n > cur->n)
		{
			listint_t *prevtmp = tmp->prev;
			listint_t *nextcur = cur->next;

			if (prevtmp != NULL)
				prevtmp->next = cur;
			else
				*list = cur;

			cur->prev = prevtmp;
			cur->next = tmp;
			tmp->prev = cur;
			tmp->next = nextcur;

			if (nextcur != NULL)
				nextcur->prev = tmp;

			print_list(*list);

			tmp = tmp->prev;
		}
		cur = cur->next;
	}
}
