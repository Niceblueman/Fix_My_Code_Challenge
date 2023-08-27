#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * add_dnodeint_end - Add a node at the end of a list
 *
 * @the_he: The address of the pointer to the first element of the list
 * @num: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **the_he, const int num)
{
	dlistint_t *new;
	dlistint_t *l;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->num = num;
	new->next = NULL;
	if (*the_he == NULL)
	{
		*the_he = new;
		new->prev = NULL;
		return (new);
	}
	l = *the_he;
	while (l->next != NULL)
	{
		l = l->next;
	}
	l->next = new;
	new->prev = l;
	return (new);
}
