/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:53:55 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:37:36 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wchar(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	int i;
	int len;

	len = bit_length(arg.u_arg.wc, 1);
	i = 0;
	if (!(conv.id_pad & MOINS)
			&& (!(conv.id_pad & ZERO)))
		while (i++ < conv.width - len)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	if (conv.id_pad & ZERO
			&& !(conv.id_pad & MOINS))
		while (i++ < conv.width - len)
			if (!(ft_putbuffer('0', buffer)))
				return (0);
	if (!ft_putwc_buff(buffer, arg.u_arg.wc))
		return (0);
	if (conv.id_pad & MOINS)
		while (i++ < conv.width - len)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}
