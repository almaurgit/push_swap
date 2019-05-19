/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:32:16 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/14 19:06:26 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_int(char *s)
{
	if (*s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit((int)*(s++)))
			return (0);
	}
	return (1);
}

int		is_overflow(char *s)
{
	intmax_t	nb;

	nb = ft_atointmax_t(s);
	if (nb < -2147483648 || nb > 2147483647)
		return (1);
	return (0);
}

int		doublon(t_pile *p, int n)
{
	int nb;

	nb = n;
	while (p)
	{
		if (nb == p->n)
			return (1);
		p = p->next;
	}
	return (0);
}

t_pile	*copy_list(t_pile *a)
{
	t_pile	*copy;
	t_pile	*start;

	start = NULL;
	if (a)
	{
		if (!(copy = malloc(sizeof(t_pile))))
			return (NULL);
		copy->n = a->n;
		copy->next = NULL;
		start = copy;
		a = a->next;
		while (a)
		{
			if (!(copy->next = malloc(sizeof(t_pile))))
				return (NULL);
			copy->next->n = a->n;
			copy->next->next = NULL;
			copy = copy->next;
			a = a->next;
		}
	}
	return (start);
}

t_pile	*partial_copy(t_pile *p, int start, int end, int sorted)
{
	t_pile	*copy;
	t_pile	*start_list;

	while (p->n < start)
		p = p->next;
	if (!(copy = malloc(sizeof(t_pile))))
		return (NULL);
	copy->n = p->n;
	copy->next = NULL;
	start_list = copy;
	p = p->next;
	while (p && p->n >= start && p->n < end)
	{
		if (!(copy->next = malloc(sizeof(t_pile))))
			return (NULL);
		copy->next->n = p->n;
		copy->next->next = NULL;
		copy = copy->next;
		p = p->next;
	}
	if (sorted)
		quicksort(&start_list, 1);
	return (start_list);
}
