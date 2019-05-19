/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:56:45 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 14:09:06 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_bis(t_pile **prev, t_pile **cur, t_pile **tail)
{
	t_pile *tmp;

	if (*prev)
		(*prev)->next = (*cur)->next;
	tmp = (*cur)->next;
	(*cur)->next = NULL;
	(*tail)->next = (*cur);
	(*tail) = (*cur);
	(*cur) = tmp;
}

t_pile	*partition_reverse
	(t_pile *head, t_pile *end, t_pile **newhead, t_pile **newend)
{
	t_pile	*pivot;
	t_pile	*prev;
	t_pile	*cur;
	t_pile	*tail;

	pivot = end;
	prev = NULL;
	cur = head;
	tail = pivot;
	while (cur != pivot)
	{
		if (cur->n >= pivot->n)
		{
			if ((*newhead) == NULL)
				(*newhead) = cur;
			prev = cur;
			cur = cur->next;
		}
		else
			partition_bis(&prev, &cur, &tail);
	}
	if ((*newhead) == NULL)
		(*newhead) = pivot;
	(*newend) = tail;
	return (pivot);
}

t_pile	*partition
	(t_pile *head, t_pile *end, t_pile **newhead, t_pile **newend)
{
	t_pile	*pivot;
	t_pile	*prev;
	t_pile	*cur;
	t_pile	*tail;

	pivot = end;
	prev = NULL;
	cur = head;
	tail = pivot;
	while (cur != pivot)
	{
		if (cur->n < pivot->n)
		{
			if ((*newhead) == NULL)
				(*newhead) = cur;
			prev = cur;
			cur = cur->next;
		}
		else
			partition_bis(&prev, &cur, &tail);
	}
	if ((*newhead) == NULL)
		(*newhead) = pivot;
	(*newend) = tail;
	return (pivot);
}

t_pile	*quicksort_recur(t_pile *head, t_pile *end, int reverse)
{
	t_pile	*newhead;
	t_pile	*newend;
	t_pile	*pivot;
	t_pile	*tmp;

	if (!head || head == end)
		return (head);
	newhead = NULL;
	newend = NULL;
	pivot = (reverse ? partition_reverse(head, end, &newhead, &newend) :
			partition(head, end, &newhead, &newend));
	if (newhead != pivot)
	{
		tmp = newhead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		newhead = quicksort_recur(newhead, tmp, reverse);
		tmp = last_elem(newhead);
		tmp->next = pivot;
	}
	pivot->next = quicksort_recur(pivot->next, newend, reverse);
	return (newhead);
}

void	quicksort(t_pile **list, int reverse)
{
	*list = quicksort_recur(*list, last_elem(*list), reverse);
}
