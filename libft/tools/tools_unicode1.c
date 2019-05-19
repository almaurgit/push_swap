/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_unicode1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:05:45 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:41:57 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_putwc_buff_bis(t_buffer *buffer, wchar_t wc, int len)
{
	int c[4];
	int i;

	i = -1;
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
	c[3] = (wc & 0x3f) | 0x80;
	c[2] = (wc & (len > 11 ? 0xfc0 : 0x7c0)) >> 6;
	c[2] |= (len > 11 ? 0x80 : 0xc0);
	if (len > 11)
		c[1] = ((wc & (len > 16 ? 0x3f000 : 0xf000)) >> 12)
			| (len > 16 ? 0x80 : 0xe0);
	c[0] = (len > 16 ? ((wc & 0x1c0000) >> 18) | 0xf0 : 0);
	while (++i < 4)
		if (c[i] && !ft_putbuffer(c[i], buffer))
			return (0);
	return (1);
}

int				ft_putwc_buff(t_buffer *buffer, wchar_t wc)
{
	int len;

	if ((0xd800 <= wc && wc <= 0xdfff) || (wc > 255 && MB_CUR_MAX == 1))
		return (0);
	len = bit_length(wc, 0);
	if (len <= 7 || (128 <= wc && wc <= 255 && MB_CUR_MAX == 1))
	{
		if (!ft_putbuffer((char)wc, buffer))
			return (0);
	}
	else if (len <= 21 && wc < 0x110000)
	{
		if (!ft_putwc_buff_bis(buffer, wc, len))
			return (0);
	}
	else
		return (0);
	return (1);
}

int				ft_putwstr_buff(t_buffer *buffer, wchar_t *ws)
{
	while (*ws)
		if (!(ft_putwc_buff(buffer, *ws++)))
			return (0);
	return (1);
}

int				ft_putwstr_prec(t_buffer *buffer, wchar_t *ws, int prec)
{
	int i;
	int	bit_l;

	i = -1;
	while (ws[++i] && prec >= 0)
	{
		bit_l = (MB_CUR_MAX == 1 && 128 <= ws[i] && ws[i] <= 255 ? 1
				: bit_length(ws[i], 1));
		if ((prec -= bit_l) >= 0
				&& !ft_putwc_buff(buffer, ws[i]))
			return (0);
	}
	return (1);
}
