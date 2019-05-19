/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:59:40 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 12:11:23 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*indexes_list(t_pile *copy, int nb, int len)
{
	int	*tab;
	int	i;
	int	k;
	int	size;

	i = nb - 1;
	k = 1;
	size = len / nb;
	if (!(tab = malloc(sizeof(int) * (nb + 1))))
		return (NULL);
	tab[nb] = copy->n;
	while (i > 0)
		tab[i--] = get_list_index(copy, k++ * size);
	tab[0] = get_max(copy) + 1;
	return (tab);
}

void	sort_sublist_bis(t_pile **a, t_pile **b, int i)
{
	while (i > 0)
	{
		ft_printf("rb\n");
		rotate(b);
		i--;
	}
	while (i < 0)
	{
		ft_printf("rrb\n");
		rev_rotate(b);
		i++;
	}
	ft_printf("pa\n");
	push(a, b);
}

void	sort_sublist(t_pile **a, t_pile **b)
{
	t_pile	*triee;
	t_pile	*p;
	t_pile	*start_triee;
	int		len;
	int		i;

	triee = copy_list(*b);
	quicksort(&triee, 1);
	start_triee = triee;
	len = length_stack(*b) + 1;
	while (--len > 0)
	{
		p = *b;
		i = 0;
		while (p && triee->n != p->n)
		{
			i++;
			p = p->next;
		}
		if (i > len / 2)
			i = i - len;
		sort_sublist_bis(a, b, i);
		triee = triee->next;
	}
	delete_stack(start_triee);
}

void	sort_sublists(t_pile **a, t_pile **b, int *tab, int len)
{
	int		i;
	int		nb;
	int		cur_nb;

	i = -1;
	while (++i < len - 1)
	{
		cur_nb = 0;
		nb = nb_elements(*a, tab[i], tab[i + 1]);
		while (cur_nb != nb)
		{
			if (tab[i] > (*a)->n && (*a)->n >= tab[i + 1])
			{
				put_inst(a, b, 1, "pb");
				cur_nb++;
			}
			else
				put_inst(a, b, 1, "rra");
		}
		while (i > 0 && (*a)->n != tab[i])
			put_inst(a, b, 1, "ra");
		sort_sublist(a, b);
	}
}

int		sort_stack(t_pile **a, t_pile **b, t_pile *copy)
{
	int		len;
	int		nb_pieces;
	int		*list_putb;

	len = length_stack(*a);
	if (len <= 5)
		sort_under_5(a, b);
	else
	{
		nb_pieces = nb_pieces_stack(len);
		if (!(list_putb = indexes_list(copy, nb_pieces, len)))
			return (0);
		sort_sublists(a, b, list_putb, nb_pieces + 1);
		free(list_putb);
	}
	return (1);
}
