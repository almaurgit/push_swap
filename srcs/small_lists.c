/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:59:31 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 14:04:40 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_pile **a, t_pile **b)
{
	if ((*a)->n == get_max(*a))
	{
		if ((*a)->next->n == get_min(*a))
			put_inst(a, b, 1, "ra");
		else
			put_inst(a, b, 2, "sa", "rra");
	}
	else if ((*a)->n == get_min(*a))
	{
		if ((*a)->next->n == get_max(*a))
			put_inst(a, b, 2, "rra", "sa");
	}
	else
	{
		if ((*a)->next->n == get_max(*a))
			put_inst(a, b, 1, "rra");
		else
			put_inst(a, b, 1, "sa");
	}
}

void	sort_under_5bis(t_pile **a, t_pile **b)
{
	if (length_stack(*a) == 3)
		sort_3(a, b);
	if (length_stack(*b) == 2)
	{
		if ((*b)->n > (*b)->next->n)
			put_inst(a, b, 2, "pa", "pa");
		else
			put_inst(a, b, 3, "sb", "pa", "pa");
	}
	else if (length_stack(*b) == 1)
	{
		if ((*b)->n > (*a)->n)
			put_inst(a, b, 2, "pa", "sa");
		else
			put_inst(a, b, 1, "pa");
	}
	if (length_stack(*a) == 2)
		if ((*a)->n > (*a)->next->n)
			put_inst(a, b, 1, "sa");
}

void	sort_under_5(t_pile **a, t_pile **b)
{
	t_pile	*triee;
	int		min;
	int		min2;

	triee = copy_list(*a);
	quicksort(&triee, 0);
	if (length_stack(*a) > 3)
	{
		min = triee->n;
		min2 = triee->next->n;
		while (length_stack(*a) > 3)
		{
			if ((*a)->n == min)
				put_inst(a, b, 1, "pb");
			else if ((*a)->n == min2)
				put_inst(a, b, 1, "pb");
			else
				put_inst(a, b, 1, "ra");
		}
	}
	sort_under_5bis(a, b);
	delete_stack(triee);
}
