/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:06:28 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/27 13:06:31 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_wstr_bis
	(t_buffer *buffer, t_conversion conv, wchar_t *ws, int fill_width)
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
		if (!ft_putwstr_prec(buffer, ws, conv.prec))
			return (0);
	}
	else if (!(ft_putwstr_buff(buffer, ws)))
		return (0);
	return (1);
}

int				ft_wstr(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	int			len;
	int			fill_width;
	wchar_t		*ws;

	fill_width = 0;
	if (!(ws = arg.u_arg.ws))
		ws = L"(null)";
	len = (conv.id_flags & PRECISION ? ft_wstrlen_prec(ws, conv.prec)
			: ft_wstrlen(ws));
	if (conv.id_flags & FIELD_WIDTH && conv.width > len)
		fill_width = conv.width - len;
	if (!(ft_wstr_bis(buffer, conv, ws, fill_width)))
		return (0);
	if (conv.id_pad & MOINS)
		while (fill_width--)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}
