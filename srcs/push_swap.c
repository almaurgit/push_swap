/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:12:55 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/14 20:21:18 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_pile	*copy;

	pile_a = NULL;
	pile_b = NULL;
	if (ac == 1)
		return (0);
	if (!(get_pile_a(ac, av, &pile_a, 1)))
		return (error(pile_a, pile_b));
	if (valid_stack(pile_a, pile_b))
		return (0);
	copy = copy_list(pile_a);
	quicksort(&copy, 0);
	if (!sort_stack(&pile_a, &pile_b, copy))
	{
		delete_stack(copy);
		return (0);
	}
	delete_piles(pile_a, pile_b);
	delete_stack(copy);
	return (0);
}
