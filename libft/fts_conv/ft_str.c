/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 03:13:43 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:36:49 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_bis
	(t_buffer *buffer, t_conversion conv, t_argument arg, int fill_width)
{
	if (!(conv.id_pad & MOINS))
	{
		if (conv.id_pad & ZERO)
		{
			while (fill_width--)
				if (!(ft_putbuffer('0', buffer)))
					return (0);
		}
		else
			while (fill_width--)
				if (!(ft_putbuffer(' ', buffer)))
					return (0);
	}
	if (conv.id_flags & PRECISION)
	{
		while (*arg.u_arg.s && conv.prec--)
			if (!(ft_putbuffer(*(arg.u_arg.s)++, buffer)))
				return (0);
	}
	else if (!(ft_putstr_buff(arg.u_arg.s, buffer)))
		return (0);
	return (1);
}

int		ft_str(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	int		fill_width;
	int		len;

	fill_width = 0;
	if (!(ft_strcmp(conv.mod, "l")))
		return (ft_wstr(buffer, conv, arg));
	if (!arg.u_arg.s)
		arg.u_arg.s = "(null)";
	len = (conv.id_flags & PRECISION ? ft_strlen_prec(arg.u_arg.s, conv.prec)
			: ft_strlen(arg.u_arg.s));
	if (conv.id_flags & FIELD_WIDTH && conv.width > len)
		fill_width = conv.width - len;
	if (!(ft_str_bis(buffer, conv, arg, fill_width)))
		return (0);
	if (conv.id_pad & MOINS)
		while (fill_width--)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}
