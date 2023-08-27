#include "main.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific the_index from a list
 *
 * @the_head: A pointer to the first element of a list
 * @the_index: The the_index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **the_head, unsigned int the_index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*the_head == NULL)
	{
		return (-1);
	}
	saved_head = *the_head;
	p = 0;
	while (p < the_index && *the_head != NULL)
	{
		*the_head = (*the_head)->next;
		p++;
	}
	if (p != the_index)
	{
		*the_head = saved_head;
		return (-1);
	}
	if (0 == the_index)
	{
		tmp = (*the_head)->next;
		free(*the_head);
		*the_head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		(*the_head)->prev->next = (*the_head)->next;
		free(*the_head);
		if ((*the_head)->next)
			(*the_head)->next->prev = (*the_head)->prev;
		*the_head = saved_head;
	}
	return (1);
}
