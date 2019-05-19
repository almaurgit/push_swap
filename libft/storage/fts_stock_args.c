/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_stock_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:55:25 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:43:54 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stock_char(va_list ap, t_list_arg *list)
{
	list->arg.type = CHAR;
	list->arg.u_arg.d = (char)va_arg(ap, int);
}

void	ft_stock_short(va_list ap, t_list_arg *list)
{
	list->arg.type = SHORT;
	list->arg.u_arg.d = (short)va_arg(ap, int);
}

void	ft_stock_int(va_list ap, t_list_arg *list)
{
	list->arg.type = INT;
	list->arg.u_arg.d = va_arg(ap, int);
}

void	ft_stock_long(va_list ap, t_list_arg *list)
{
	list->arg.type = LONG;
	list->arg.u_arg.d = va_arg(ap, long);
}

void	ft_stock_longlong(va_list ap, t_list_arg *list)
{
	list->arg.type = LONGLONG;
	list->arg.u_arg.d = va_arg(ap, long long);
}
