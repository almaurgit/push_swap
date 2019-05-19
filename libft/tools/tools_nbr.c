/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 03:40:19 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:41:08 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		uint_length(uintmax_t n, uintmax_t base)
{
	int len;

	len = 1;
	while (n >= base)
	{
		n /= base;
		len++;
	}
	return (len);
}

int		int_length(intmax_t n, uintmax_t base)
{
	uintmax_t	un;
	int			len;

	un = n;
	len = 1;
	if (n < 0)
		un = (uintmax_t)(-n);
	while (un >= base)
	{
		un /= base;
		len++;
	}
	return (len);
}

int		ft_putunbr_buff_base
	(uintmax_t nb, uintmax_t base, int maj, t_buffer *buffer)
{
	char		*tab;

	if (nb >= base)
		ft_putnbr_buff_base(nb / base, base, maj, buffer);
	tab = (maj ? "0123456789ABCDEF" : "0123456789abcdef");
	if (!(ft_putbuffer(tab[nb % base], buffer)))
		return (0);
	return (1);
}

int		ft_putnbr_buff_base
	(intmax_t nb, uintmax_t base, int maj, t_buffer *buffer)
{
	uintmax_t	un;
	char		*tab;

	un = nb;
	if (nb < 0)
		un = -nb;
	if (un >= base)
		ft_putnbr_buff_base(un / base, base, maj, buffer);
	tab = (maj ? "0123456789ABCDEF" : "0123456789abcdef");
	if (!(ft_putbuffer(tab[un % base], buffer)))
		return (0);
	return (1);
}

int		ft_strlen_prec(char *s, int prec)
{
	int i;

	i = 0;
	while (s[i] && i < prec)
		i++;
	return (i);
}
