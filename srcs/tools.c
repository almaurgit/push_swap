/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:39:38 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/14 17:35:37 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_posmin(t_pile *a)
{
	int		i;
	int		min;
	int		pos;

	i = 1;
	pos = 0;
	if (a)
	{
		min = a->n;
		while (a)
		{
			if (a->n < min)
			{
				pos = i;
				min = a->n;
			}
			a = a->next;
			i++;
		}
	}
	return (pos);
}

int		get_posmax(t_pile *a)
{
	int		i;
	int		max;
	int		pos;

	i = 1;
	pos = 0;
	if (a)
	{
		max = a->n;
		while (a)
		{
			if (a->n > max)
			{
				pos = i;
				max = a->n;
			}
			a = a->next;
			i++;
		}
	}
	return (pos);
}

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		min(int a, int b)
{
	return (a < b ? a : b);
}

t_pile	*last_elem(t_pile *p)
{
	while (p && p->next)
		p = p->next;
	return (p);
}
