#include "sort.h"

/**
 * swap_left_to_right - Swap from left to right
 * @list: pointer to list
 * @tmp: pointer to list head
 * Return: Nothing.
 */
void swap_left_to_right(listint_t **list, listint_t *tmp)
{
	listint_t *aux;

	if (list)
	{
		aux = tmp->next;
		if (aux->next != NULL)
		{
			aux->next->prev = tmp;
		}
		tmp->next = aux->next;
		aux->prev = tmp->prev;
		aux->next = tmp;
		tmp->prev = aux;
		if (aux->prev != NULL)
		{
			aux->prev->next = aux;
		}
		else
		{
			*list = aux;
		}
		print_list(*list);
	}
}
/**
 * swap_right_to_left - Swap from right to left
 * @list: pointer to list
 * @tmp: pointer to list head
 * Return: Nothing.
 */
void swap_right_to_left(listint_t **list, listint_t *tmp)
{
	if (list)
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
}

/**
 * cocktail_sort_list - Swap from left to right
 * @list: pointer to list
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int flag;

	if (list)
	{
		tmp = *list;
		flag = 1;
		do {
			flag = 0;
			while (tmp->next != NULL)
			{
				if (tmp->n > tmp->next->n)
				{
					swap_left_to_right(list, tmp);
					flag = 1;
				}
				else
					tmp = tmp->next;
			}
			if (flag == 0)
			{
				break;
			}
			flag = 0;
			while (tmp->prev != NULL)
			{
				if (tmp->prev->n > tmp->n)
				{
					swap_right_to_left(list, tmp);
					flag = 1;
				}
				else
					tmp = tmp->prev;
			}
		} while (flag == 1);
	}
}
