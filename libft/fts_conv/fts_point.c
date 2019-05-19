/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:03:52 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:45:07 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_point_bis
	(t_buffer *buffer, t_conversion conv, int fill_width)
{
	if (!(conv.id_pad & MOINS)
			&& (!(conv.id_pad & ZERO) || (conv.id_flags & PRECISION)))
		while (fill_width-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	if (!(ft_putstr_buff("0x", buffer)))
		return (0);
	return (1);
}

int		ft_point_ter
	(t_buffer *buffer, t_conversion conv, t_argument arg, int fill[2])
{
	if (conv.id_pad & ZERO && !(conv.id_flags & PRECISION)
			&& !(conv.id_pad & MOINS))
		while (fill[0]-- > 0)
			if (!(ft_putbuffer('0', buffer)))
				return (0);
	while (fill[1]-- > 0)
		if (!(ft_putbuffer('0', buffer)))
			return (0);
	if (!(!arg.u_arg.p && conv.id_flags & PRECISION && !conv.prec)
		&& !(ft_putunbr_buff_base((uintmax_t)arg.u_arg.p, 16, 0, buffer)))
		return (0);
	return (1);
}

int		ft_point(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	int		len;
	int		fill[2];

	len = uint_length((uintmax_t)arg.u_arg.p, 16);
	fill[0] = 0;
	fill[1] = 0;
	if ((conv.id_flags & PRECISION) && conv.prec > len)
		fill[1] = conv.prec - len;
	len = len + 2;
	if (!(arg.u_arg.p) && conv.id_flags & PRECISION && !conv.prec)
		len = 0;
	if ((conv.id_flags & FIELD_WIDTH) && conv.width > fill[1] + len)
		fill[0] = conv.width - fill[1] - len;
	if (!ft_point_bis(buffer, conv, fill[0])
			|| !ft_point_ter(buffer, conv, arg, fill))
		return (0);
	if (conv.id_pad & MOINS)
		while (fill[0]-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}
