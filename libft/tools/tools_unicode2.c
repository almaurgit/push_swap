/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_unicode2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:09:46 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/21 23:20:29 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *ws)
{
	int		len;
	int		bit_l;

	len = 0;
	if (!*ws)
		return (0);
	while (*ws)
	{
		bit_l = (MB_CUR_MAX == 1 && 128 <= *ws && *ws <= 255 ? 1
				: bit_length(*ws, 1));
		len += bit_l;
		ws++;
	}
	return (len);
}

int		ft_wstrlen_prec(wchar_t *ws, int prec)
{
	int		len;
	int		i;
	int		bit_l;

	len = 0;
	i = 0;
	if (!*ws)
		return (0);
	while (ws[i] && len < prec)
	{
		bit_l = (MB_CUR_MAX == 1 && 128 <= ws[i] && ws[i] <= 255 ? 1
				: bit_length(ws[i], 1));
		if (len + bit_l <= prec)
			len += bit_l;
		else
			break ;
		i++;
	}
	return (len);
}

int		bit_length(uintmax_t n, int lenbytes)
{
	int len;

	if (!n)
		return (1);
	len = 1;
	while (n >>= 1)
		len++;
	if (!lenbytes)
		return (len);
	else
	{
		if (len <= 7)
			len = 1;
		else if (len <= 11)
			len = 2;
		else if (len <= 16)
			len = 3;
		else if (len <= 21)
			len = 4;
		else
			return (0);
	}
	return (len);
}
