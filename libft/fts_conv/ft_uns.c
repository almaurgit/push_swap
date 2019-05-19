/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:55:20 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:44:53 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uns_bis
	(t_buffer *buffer, t_conversion conv, int fill_width)
{
	if (!(conv.id_pad & MOINS)
			&& (!(conv.id_pad & ZERO) || (conv.id_flags & PRECISION)))
		while (fill_width-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}

int		ft_uns_ter
	(t_buffer *buffer, t_conversion conv, t_argument arg, int fill[2])
{
	if (conv.id_pad & ZERO && !(conv.id_flags & PRECISION)
			&& !(conv.id_pad & MOINS))
		while (fill[0]--)
			if (!(ft_putbuffer('0', buffer)))
				return (0);
	while (fill[1]-- > 0)
		if (!(ft_putbuffer('0', buffer)))
			return (0);
	if (!(!arg.u_arg.u && conv.id_flags & PRECISION && !conv.prec)
			&& !(ft_putunbr_buff_base(arg.u_arg.u, 10, 0, buffer)))
		return (0);
	return (1);
}

int		ft_uns(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	int len;
	int	fill[2];

	len = uint_length(arg.u_arg.u, 10);
	fill[0] = 0;
	fill[1] = 0;
	if ((conv.id_flags & PRECISION) && conv.prec > len)
		fill[1] = conv.prec - len;
	if (!(arg.u_arg.u) && conv.id_flags & PRECISION && !conv.prec)
		len = 0;
	if ((conv.id_flags & FIELD_WIDTH) && conv.width > fill[1] + len)
		fill[0] = conv.width - fill[1] - len;
	if (!ft_uns_bis(buffer, conv, fill[0])
			|| !ft_uns_ter(buffer, conv, arg, fill))
		return (0);
	if (conv.id_pad & MOINS)
		while (fill[0]-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}
