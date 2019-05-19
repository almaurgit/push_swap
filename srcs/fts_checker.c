/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:21:57 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 14:01:46 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		length_stack(t_pile *p)
{
	int		len;

	len = 0;
	while (p)
	{
		p = p->next;
		len++;
	}
	return (len);
}

void	swap(t_pile **p)
{
	t_pile *tmp;

	if (length_stack(*p) < 2)
		return ;
	else
	{
		tmp = (*p)->next;
		(*p)->next = tmp->next;
		tmp->next = *p;
		*p = tmp;
	}
}

void	rotate(t_pile **p)
{
	t_pile	*tmp;

	if (length_stack(*p) < 2)
		return ;
	tmp = *p;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *p;
	*p = (*p)->next;
	tmp->next->next = NULL;
}

void	rev_rotate(t_pile **p)
{
	t_pile	*tmp;

	if (length_stack(*p) < 2)
		return ;
	tmp = *p;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *p;
	*p = tmp->next;
	tmp->next = NULL;
}

void	push(t_pile **a, t_pile **b)
{
	int	n;

	if (length_stack(*b) < 1)
		return ;
	n = (*b)->n;
	remove_pile(b);
	add_pile(a, n);
}
