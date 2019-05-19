/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 02:36:02 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:39:14 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexa_bis
	(t_buffer *buffer, t_conversion conv, t_argument arg, int fill_width)
{
	int maj;

	if (!(conv.id_pad & MOINS)
			&& (!(conv.id_pad & ZERO) || (conv.id_flags & PRECISION)))
		while (fill_width-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	maj = (conv.char_conv == 'x' ? 0 : 1);
	if (conv.id_pad & HASHTAG && arg.u_arg.u)
		if (!(ft_putstr_buff((maj ? "0X" : "0x"), buffer)))
			return (0);
	return (1);
}

int		ft_hexa_ter
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
	if (!(!arg.u_arg.u && conv.id_flags & PRECISION && !conv.prec)
			&& !(ft_putunbr_buff_base(
					arg.u_arg.u, 16, conv.char_conv == 'x' ? 0 : 1, buffer)))
		return (0);
	return (1);
}

int		ft_hexa(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	int		len;
	int		fill[2];

	len = uint_length((uintmax_t)arg.u_arg.u, 16);
	fill[0] = 0;
	fill[1] = 0;
	if ((conv.id_flags & PRECISION) && conv.prec > len)
		fill[1] = conv.prec - len;
	if (conv.id_pad & HASHTAG && arg.u_arg.u)
		len = len + 2;
	if (!(arg.u_arg.u) && conv.id_flags & PRECISION && !conv.prec)
		len = 0;
	if ((conv.id_flags & FIELD_WIDTH) && conv.width > fill[1] + len)
		fill[0] = conv.width - fill[1] - len;
	if (!ft_hexa_bis(buffer, conv, arg, fill[0])
			|| !ft_hexa_ter(buffer, conv, arg, fill))
		return (0);
	if (conv.id_pad & MOINS)
		while (fill[0]-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}
