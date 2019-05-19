/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 15:53:37 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/23 13:29:26 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	pass_conversion(const char *format, t_conversion *conv, int j)
{
	int i;

	i = 0;
	while (format[j + i] == conv->conversion[i] && format[j + i])
		i++;
	return (j + i);
}

int			get_buffer
	(const char *format, t_buffer *buffer,
	t_list_conv *lc, t_list_arg *listarg)
{
	int			i;
	t_list_arg	*begin_listarg;

	i = 0;
	begin_listarg = listarg;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			if (!(ft_putbuffer(format[i++], buffer)))
				return (0);
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (0);
			if (lc->conv.id_flags & FLAG_DOLLAR && !(lc->conv.type == PERCENT))
				listarg = arg_dollar(lc->conv, begin_listarg);
			if (!(lc->conv.ft_conv(buffer, lc->conv, listarg->arg)))
				return (0);
			i = pass_conversion(format, &(lc->conv), i + 1);
			lc = (lc->next ? lc->next : lc);
			if (!(lc->conv.id_flags & FLAG_DOLLAR))
				listarg = (listarg->next ? listarg->next : listarg);
		}
	}
	return (1);
}
