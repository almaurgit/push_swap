/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 12:59:59 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/14 18:56:15 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		get_flags_ck(char **av, char *flag)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	*flag = 0;
	while (av[i] && av[i][j] == '-' && av[i][j + 1])
	{
		j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				return (i);
			if (av[i][j] == 'v')
				*flag |= VISU;
			else if (av[i][j] == 'n')
				*flag |= NBINST;
			else
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

int		main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	*inst;
	char	flags;
	int		ret;

	pile_a = NULL;
	pile_b = NULL;
	inst = NULL;
	if (ac > 1)
		ret = get_flags_ck(av, &flags);
	else
		return (0);
	if (!(get_pile_a(ac, av, &pile_a, ret)))
		return (error(pile_a, pile_b));
	if ((ret = read_instructions(inst, &pile_a, &pile_b, flags)) == -1)
		return (error(pile_a, pile_b));
	if (valid_stack(pile_a, pile_b))
		ft_printf((flags & NBINST ? "OK - %d instructions\n" : "OK\n"), ret);
	else
	{
		delete_piles(pile_a, pile_b);
		ft_printf("KO\n");
	}
	return (0);
}
