/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pile_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:06:12 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/14 20:01:12 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_pile(t_pile **p)
{
	t_pile	*tmp;

	if (length_stack(*p) == 0)
		return ;
	else if (length_stack(*p) == 1)
	{
		free(*p);
		*p = NULL;
	}
	else
	{
		tmp = (*p)->next;
		free(*p);
		*p = tmp;
	}
}

int		add_pile(t_pile **p, int n)
{
	t_pile	*new;
	int		nb;

	nb = n;
	if (!(new = malloc(sizeof(t_pile))))
		return (0);
	if (!(*p))
	{
		new->n = n;
		new->next = NULL;
		*p = new;
	}
	else
	{
		if (doublon(*p, n))
		{
			free(new);
			return (0);
		}
		new->n = n;
		new->next = *p;
		*p = new;
	}
	return (1);
}

int		get_pile_a(int ac, char **av, t_pile **a, int i)
{
	if (i == -1)
		return (0);
	if (ac == i)
		return (0);
	while (ac > i)
	{
		if (is_int(av[ac - 1]) && !is_overflow(av[ac - 1]))
		{
			if (!(add_pile(a, ft_atoi(av[ac - 1]))))
				return (0);
		}
		else
			return (0);
		ac--;
	}
	return (1);
}
