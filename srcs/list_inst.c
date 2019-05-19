/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:09:45 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 14:02:18 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_inst(t_pile **a, t_pile **b, int nb, ...)
{
	va_list	ap;
	int		i;
	char	*inst;

	i = 0;
	va_start(ap, nb);
	while (i < nb)
	{
		inst = va_arg(ap, char *);
		ft_printf(inst);
		ft_printf("\n");
		exec_instructions(inst, a, b);
		i++;
	}
	va_end(ap);
}
