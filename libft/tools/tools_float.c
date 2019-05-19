/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 07:20:44 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:48:43 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			mantissa_length(uintmax_t mantissa)
{
	int len_mantissa;

	len_mantissa = 0;
	while (mantissa)
	{
		len_mantissa++;
		mantissa <<= 4;
	}
	return (len_mantissa);
}

int			floathex_length
	(uintmax_t d, t_conversion conv, int len_mantissa, intmax_t exp)
{
	int			len;
	uintmax_t	mantissa;

	mantissa = (d & 0x000fffffffffffff) << 12;
	len = 5;
	if (d & 0x8000000000000000 || conv.id_pad & PLUS || conv.id_pad & SPACE)
		len++;
	if (conv.id_pad & HASHTAG ||
			(!(conv.id_flags & PRECISION) && mantissa > 0)
			|| ((conv.id_flags & PRECISION) && conv.prec > 0))
		len++;
	len += int_length(exp, 10);
	len += len_mantissa;
	return (len);
}

uintmax_t	arrondi(uintmax_t mantissa, int prec)
{
	uintmax_t	flag1;

	flag1 = 0x000000000000000f;
	if ((mantissa & (flag1 << (60 - 4 * prec)))
			>= ((uintmax_t)0x0000000000000008 << (60 - 4 * prec)))
	{
		if (prec > 0)
			mantissa += ((uintmax_t)0x0000000000000001 << (64 - 4 * prec));
		else
			mantissa += (uintmax_t)0x1000000000000000;
	}
	if (prec > 0)
		mantissa &= ((uintmax_t)0xffffffffffffffff << (64 - 4 * prec));
	else
		mantissa &= 0xf000000000000000;
	return (mantissa);
}

void		unnormalized_nb(uintmax_t *mantissa, intmax_t *exp)
{
	uintmax_t	m;
	intmax_t	new_exp;

	new_exp = 0;
	m = *mantissa;
	while (!(0x8000000000000000 & m))
	{
		new_exp++;
		m <<= 1;
	}
	m <<= 1;
	*mantissa = m;
	*exp = *exp - 0x3ff - new_exp;
}

int			ft_put_hex(uintmax_t d, t_buffer *buffer, t_conversion conv)
{
	char		*tab;
	uintmax_t	i;

	i = 0;
	tab = (conv.char_conv == 'A' ? "0123456789ABCDEF" : "0123456789abcdef");
	while (d && (!(conv.id_flags & PRECISION)
				|| ((conv.id_flags & PRECISION) && conv.prec)))
	{
		i = 0;
		while (i < 16)
		{
			if ((d & 0xf000000000000000) == (i << 60))
				if (!ft_putbuffer(tab[i], buffer))
					return (0);
			i++;
		}
		d <<= 4;
		conv.prec--;
	}
	if (conv.id_flags & PRECISION && conv.prec)
		while (conv.prec-- > 0)
			if (!(ft_putbuffer('0', buffer)))
				return (0);
	return (1);
}
