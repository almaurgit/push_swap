/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 05:13:57 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/23 13:44:31 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag_dollar(t_list_conv *list)
{
	while (list)
	{
		if (list->conv.id_flags & FLAG_DOLLAR)
			return (1);
		list = list->next;
	}
	return (0);
}

int		no_duplicates_dollar(t_list_conv *listconv)
{
	t_list_conv	*list;
	t_list_conv *tmp;

	list = listconv;
	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (tmp->conv.pos && tmp->conv.pos == list->conv.pos)
				return (0);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (1);
}

int		valid_dollar(t_list_conv *list)
{
	t_list_conv	*tmp;

	tmp = list;
	while (list)
	{
		if (!(list->conv.id_flags & FLAG_DOLLAR))
		{
			if (!(list->conv.type == PERCENT))
				return (0);
			else
			{
				list->conv.id_flags |= FLAG_DOLLAR;
				list->conv.pos = 0;
			}
		}
		list = list->next;
	}
	return (no_duplicates_dollar(tmp));
}
