/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:43:41 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:33:57 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_n(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	if (conv.type == STRING)
		return (0);
	else
		*((uintmax_t *)arg.u_arg.n) = buffer->ind;
	return (1);
}
