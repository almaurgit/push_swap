/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexfloat2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 07:22:33 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:18:45 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	nan_inf_bis
	(uintmax_t sign, uintmax_t mantissa, t_conversion conv, t_buffer *buffer)
{
	int		maj;

	maj = (conv.char_conv == 'A' ? 1 : 0);
	if (!mantissa && !sign && conv.id_pad & PLUS)
		if (!ft_putbuffer('+', buffer))
			return (0);
	if (!mantissa && sign)
		if (!(ft_putbuffer('-', buffer)))
			return (0);
	if (!mantissa)
		if (!ft_putstr_buff(maj ? "INF" : "inf", buffer))
			return (0);
	if (mantissa)
		if (!ft_putstr_buff(maj ? "NAN" : "nan", buffer))
			return (0);
	return (1);
}

int			nan_inf
	(uintmax_t sign, uintmax_t mantissa, t_conversion conv, t_buffer *buffer)
{
	int		fill_width;
	int		len;

	len = 3;
	fill_width = 0;
	if (!mantissa && sign)
		len++;
	if (conv.id_flags & FIELD_WIDTH && conv.width > len)
		fill_width = conv.width - len;
	if (!(conv.id_pad & MOINS))
		while (fill_width--)
			if (!ft_putbuffer(' ', buffer))
				return (0);
	if (!nan_inf_bis(sign, mantissa, conv, buffer))
		return (0);
	if (conv.id_pad & MOINS)
		while (fill_width--)
			if (!ft_putbuffer(' ', buffer))
				return (0);
	return (1);
}
