/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:57:17 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:34:27 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	int i;

	i = 0;
	if (!ft_strcmp(conv.mod, "l"))
		return (ft_wchar(buffer, conv, arg));
	if (!(conv.id_pad & MOINS)
			&& (!(conv.id_pad & ZERO)))
		while (i++ < conv.width - 1)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	if (conv.id_pad & ZERO
			&& !(conv.id_pad & MOINS))
		while (i++ < conv.width - 1)
			if (!(ft_putbuffer('0', buffer)))
				return (0);
	if (!(ft_putbuffer(arg.u_arg.d, buffer)))
		return (0);
	if (conv.id_pad & MOINS)
		while (i++ < conv.width - 1)
			if (!(ft_putbuffer(' ', buffer)))
				return (0);
	return (1);
}
