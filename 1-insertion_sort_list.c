#include "sort.h"

/**
 * insertion_sort_list - Insert sort algorithm
 * @list: pointer to list
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;

	if (list)
	{
		tmp = (*list)->next;
		while (tmp != NULL)
		{
			while (tmp->prev && tmp->prev->n > tmp->n)
			{
				if (tmp->next != NULL)
				{
					tmp->next->prev = tmp->prev;
				}
				tmp->prev->next = tmp->next;
				tmp->next = tmp->prev;
				tmp->prev = tmp->prev->prev;
				tmp->next->prev = tmp;
				if (tmp->prev != NULL)
				{
					tmp->prev->next = tmp;
				}
				else
				{
					*list = tmp;
				}
				print_list(*list);
			}
			tmp = tmp->next;
		}
	}
}
