/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 05:10:47 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/23 13:44:10 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		asterisk(t_conversion *conv, va_list ap)
{
	int	width;
	int prec;

	if (conv->id_flags & WIDTH_ASTERISK)
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			conv->width = -width;
			conv->id_pad |= MOINS;
		}
		else
			conv->width = width;
	}
	if (conv->id_flags & PRECISION_ASTERISK)
	{
		prec = va_arg(ap, int);
		if (prec < 0)
			conv->id_flags &= PRECISION - 1;
		else
			conv->prec = prec;
	}
}

t_list_arg	*stock_args_dollar(t_list_conv *listconv, va_list ap)
{
	int			n;
	t_list_conv	*tmp;
	t_list_arg	*list;
	int			pos_max;

	n = 1;
	if (!(pos_max = get_pos_max(listconv)))
		return (NULL);
	while (n <= pos_max)
	{
		tmp = listconv;
		while (tmp->conv.pos != n && tmp)
			tmp = tmp->next;
		if (n == 1)
		{
			if (!(list = create_list_args(tmp->conv.type, ap)))
				return (NULL);
		}
		else if (!(add_list_args(list, tmp->conv.type, ap)))
			return (NULL);
		n++;
	}
	return (list);
}

int			get_pos_max(t_list_conv *listconv)
{
	int			max;
	int			compteur;
	t_list_conv	*list;

	max = 0;
	compteur = 0;
	if (listconv)
	{
		list = listconv;
		max = listconv->conv.pos;
		while (list)
		{
			if (!(list->conv.type == PERCENT))
				compteur++;
			if (list->conv.pos > max)
				max = list->conv.pos;
			list = list->next;
		}
	}
	return (max > compteur ? 0 : max);
}

t_list_arg	*arg_dollar(t_conversion conv, t_list_arg *listarg)
{
	int			i;
	t_list_arg	*tmp;

	i = 1;
	tmp = listarg;
	while (i < conv.pos)
	{
		tmp = (tmp->next ? tmp->next : tmp);
		i++;
	}
	return (tmp);
}
