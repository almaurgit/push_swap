/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 23:25:55 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:51:56 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hexfloat_split1
	(t_buffer *buffer, t_conversion conv, t_argument arg, t_params_a *p)
{
	p->len = floathex_length(arg.u_arg.u, conv,
			(conv.id_flags & PRECISION ? conv.prec : p->len_mantissa), p->exp);
	if ((conv.id_flags & FIELD_WIDTH) && conv.width > p->len)
		p->fill_width = conv.width - p->len;
	if (!(conv.id_pad & MOINS) && !(conv.id_pad & ZERO))
		while (p->fill_width-- > 0)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	if (!(arg.u_arg.u & 0x8000000000000000) && conv.id_pad & PLUS)
	{
		if (!ft_putbuffer('+', buffer))
			return (0);
	}
	else if (!(arg.u_arg.u & 0x8000000000000000) && (conv.id_pad & SPACE))
	{
		if (!ft_putbuffer(' ', buffer))
			return (0);
	}
	else if (arg.u_arg.u & 0x8000000000000000)
		if (!ft_putbuffer('-', buffer))
			return (0);
	return (1);
}

static	int	ft_hexfloat_split2
	(t_buffer *buffer, t_conversion conv, t_params_a *p)
{
	if (!ft_putstr_buff(conv.char_conv == 'A' ? "0X" : "0x", buffer))
		return (0);
	if (!(conv.id_pad & MOINS) && (conv.id_pad & ZERO))
		while (p->fill_width-- > 0)
			if (!(ft_putbuffer('0', buffer)))
				return (0);
	if (!p->mantissa && p->len_mantissa)
	{
		if (!ft_putbuffer('2', buffer))
			return (0);
	}
	else if (!p->mantissa && !p->exp)
	{
		if (!ft_putbuffer('0', buffer))
			return (0);
	}
	else if (!ft_putbuffer('1', buffer))
		return (0);
	if (conv.id_pad & HASHTAG ||
			(!(conv.id_flags & PRECISION) && p->mantissa > 0)
			|| ((conv.id_flags & PRECISION) && conv.prec > 0))
		if (!ft_putbuffer('.', buffer))
			return (0);
	return (1);
}

static	int	ft_hexfloat_split3
	(t_buffer *buffer, t_conversion conv, t_params_a *p)
{
	if (!ft_put_hex(p->mantissa, buffer, conv))
		return (0);
	if (!ft_putbuffer(conv.char_conv == 'A' ? 'P' : 'p', buffer))
		return (0);
	if (p->exp >= 0)
	{
		if (!ft_putbuffer('+', buffer)
				|| !ft_putunbr_buff_base(p->exp, 10, 0, buffer))
			return (0);
	}
	else if (!ft_putbuffer('-', buffer)
			|| !ft_putunbr_buff_base(-p->exp, 10, 0, buffer))
		return (0);
	if (conv.id_pad & MOINS)
		while (p->fill_width-- > 0)
			if (!ft_putbuffer(' ', buffer))
				return (0);
	return (1);
}

void		init_params(t_params_a *p, t_argument arg)
{
	p->sign = arg.u_arg.u & 0x8000000000000000;
	p->exp = (arg.u_arg.u & 0x7ff0000000000000) >> 52;
	p->mantissa = (arg.u_arg.u & 0x000fffffffffffff) << 12;
	p->len = 0;
	p->len_mantissa = 0;
	p->fill_width = 0;
	p->fill_prec = 0;
}

int			ft_hexfloat(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	t_params_a	p;

	init_params(&p, arg);
	if (p.exp == 0x7ff)
		return (nan_inf(p.sign, p.mantissa, conv, buffer));
	else if (!p.exp && p.mantissa)
		unnormalized_nb(&(p.mantissa), &(p.exp));
	else
		p.exp = (p.exp ? p.exp - 0x3ff : 0);
	p.len_mantissa = mantissa_length(p.mantissa);
	if (conv.id_flags & PRECISION)
	{
		if (conv.prec > p.len_mantissa)
			p.fill_prec = conv.prec - p.len_mantissa;
		else if (conv.prec < p.len_mantissa)
			if (!(p.mantissa = arrondi(p.mantissa, conv.prec)))
				p.fill_prec = conv.prec;
	}
	if (!ft_hexfloat_split1(buffer, conv, arg, &p)
		|| !ft_hexfloat_split2(buffer, conv, &p)
		|| !ft_hexfloat_split3(buffer, conv, &p))
		return (0);
	return (1);
}
