/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:33:50 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/14 18:14:08 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		valid_instruction(char *s)
{
	if (ft_strcmp(s, "sa") && ft_strcmp(s, "sb") && ft_strcmp(s, "ss")
			&& ft_strcmp(s, "ra") && ft_strcmp(s, "rb") && ft_strcmp(s, "rr")
			&& ft_strcmp(s, "rra") && ft_strcmp(s, "rrb") && ft_strcmp(s, "rrr")
			&& ft_strcmp(s, "pa") && ft_strcmp(s, "pb"))
		return (0);
	return (1);
}

int		exec_instructions_bis(char *s, t_pile **a, t_pile **b)
{
	if (!ft_strcmp(s, "rra"))
		rev_rotate(a);
	else if (!ft_strcmp(s, "rrb"))
		rev_rotate(b);
	else if (!ft_strcmp(s, "rrr"))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else if (!ft_strcmp(s, "pa"))
		push(a, b);
	else if (!ft_strcmp(s, "pb"))
		push(b, a);
	return (1);
}

int		exec_instructions(char *s, t_pile **a, t_pile **b)
{
	if (!ft_strcmp(s, "sa"))
		swap(a);
	else if (!ft_strcmp(s, "sb"))
		swap(b);
	else if (!ft_strcmp(s, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(s, "ra"))
		rotate(a);
	else if (!ft_strcmp(s, "rb"))
		rotate(b);
	else if (!ft_strcmp(s, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else
		return (exec_instructions_bis(s, a, b));
	return (1);
}

void	visu(t_pile *a, t_pile *b, char *inst, int nb)
{
	usleep(25000);
	ft_printf("\033[2J\033[f");
	ft_printf("\033[35;m");
	ft_printf("%s - %d\n", inst, nb);
	ft_printf("\n");
	ft_printf("\033[36;m");
	print_list(a);
	ft_printf("\n");
	ft_printf("\033[32;m");
	print_list(b);
}

int		read_instructions(char *inst, t_pile **a, t_pile **b, char flag)
{
	int		ret;
	int		nb;

	nb = 0;
	while ((ret = get_next_line(0, &inst)) > 0)
	{
		if (!valid_instruction(inst))
		{
			free(inst);
			return (-1);
		}
		exec_instructions(inst, a, b);
		nb++;
		if (flag & VISU)
			visu(*a, *b, inst, nb);
		free(inst);
	}
	return (nb);
}
