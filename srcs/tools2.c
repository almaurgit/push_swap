/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:55:26 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/14 17:35:53 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		nb_pieces_stack(int len)
{
	double a;
	double b;

	if (len < 100)
	{
		a = 0.04;
		b = 1.;
	}
	else
	{
		a = 0.01;
		b = 3.5;
	}
	return ((int)(a * (double)len + b));
}

int		get_list_index(t_pile *copy, int index)
{
	while (index--)
		copy = copy->next;
	return (copy->n);
}

int		get_max(t_pile *a)
{
	int	max;

	max = 0;
	if (a)
	{
		max = a->n;
		while (a)
		{
			if (a->n > max)
				max = a->n;
			a = a->next;
		}
	}
	return (max);
}

int		get_min(t_pile *a)
{
	int	min;

	min = 0;
	if (a)
	{
		min = a->n;
		while (a)
		{
			if (a->n < min)
				min = a->n;
			a = a->next;
		}
	}
	return (min);
}

int		nb_elements(t_pile *a, int max, int min)
{
	int nb;

	nb = 0;
	while (a)
	{
		if (min <= a->n && a->n < max)
			nb++;
		a = a->next;
	}
	return (nb);
}
