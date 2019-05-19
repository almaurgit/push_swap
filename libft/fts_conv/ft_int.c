/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:40:39 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:36:03 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_bis
	(t_buffer *buffer, t_conversion conv, t_argument arg, int fill_width)
{
	if (!(conv.id_pad & MOINS)
			&& (!(conv.id_pad & ZERO) || (conv.id_flags & PRECISION)))
		while (fill_width-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	if (conv.id_pad & PLUS && arg.u_arg.d >= 0)
	{
		if (!(ft_putbuffer('+', buffer)))
			return (0);
	}
	else if (conv.id_pad & SPACE && arg.u_arg.d >= 0)
	{
		if (!(ft_putbuffer(' ', buffer)))
			return (0);
	}
	else if (arg.u_arg.d < 0)
		if (!(ft_putbuffer('-', buffer)))
			return (0);
	return (1);
}

int		ft_int_ter
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
	if (!(!arg.u_arg.d && conv.id_flags & PRECISION && !conv.prec)
			&& !(ft_putnbr_buff_base(arg.u_arg.d, 10, 0, buffer)))
		return (0);
	return (1);
}

int		ft_int(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	int len;
	int	fill[2];

	len = int_length((intmax_t)arg.u_arg.d, 10);
	fill[0] = 0;
	fill[1] = 0;
	if ((conv.id_flags & PRECISION) && conv.prec > len)
		fill[1] = conv.prec - len;
	if ((arg.u_arg.d >= 0 && (conv.id_pad & SPACE || conv.id_pad & PLUS))
			|| arg.u_arg.d < 0)
		len++;
	if (!(arg.u_arg.d) && conv.id_flags & PRECISION && !conv.prec)
		len = 0;
	if ((conv.id_flags & FIELD_WIDTH) && conv.width > fill[1] + len)
		fill[0] = conv.width - fill[1] - len;
	if (!ft_int_bis(buffer, conv, arg, fill[0])
			|| !ft_int_ter(buffer, conv, arg, fill))
		return (0);
	if (conv.id_pad & MOINS)
		while (fill[0]-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}
