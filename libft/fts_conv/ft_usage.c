/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 12:20:26 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:51:25 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_usage(t_buffer *buffer, t_conversion conv, t_argument arg)
{
	if (buffer || conv.type || arg.type)
		;
	return (1);
}
