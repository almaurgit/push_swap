/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:06:32 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 14:54:24 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_piles(t_pile *a, t_pile *b)
{
	t_pile	*tmp;

	while (a || b)
	{
		if (a)
		{
			tmp = a->next;
			free(a);
			a = tmp;
		}
		if (b)
		{
			tmp = b->next;
			free(b);
			b = tmp;
		}
	}
}

int		error(t_pile *a, t_pile *b)
{
	ft_printf("Error\n");
	delete_piles(a, b);
	return (0);
}

int		valid_stack(t_pile *a, t_pile *b)
{
	t_pile	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->n > tmp->next->n)
				return (0);
		}
		tmp = tmp->next;
	}
	if (!b)
	{
		delete_piles(a, b);
		return (1);
	}
	return (0);
}

void	print_list(t_pile *a)
{
	while (a)
	{
		ft_printf("%d ", a->n);
		a = a->next;
	}
	ft_printf("\n");
}

void	delete_stack(t_pile *p)
{
	t_pile *tmp;

	while (p)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
}
