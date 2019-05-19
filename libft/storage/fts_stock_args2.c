/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_stock_args2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:28:32 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:42:43 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stock_uchar(va_list ap, t_list_arg *list)
{
	list->arg.type = UCHAR;
	list->arg.u_arg.u = (unsigned char)va_arg(ap, unsigned int);
}

void	ft_stock_ushort(va_list ap, t_list_arg *list)
{
	list->arg.type = USHORT;
	list->arg.u_arg.u = (unsigned short)va_arg(ap, unsigned int);
}

void	ft_stock_uint(va_list ap, t_list_arg *list)
{
	list->arg.type = UINT;
	list->arg.u_arg.u = va_arg(ap, unsigned int);
}

void	ft_stock_ulong(va_list ap, t_list_arg *list)
{
	list->arg.type = ULONG;
	list->arg.u_arg.u = va_arg(ap, unsigned long);
}

void	ft_stock_ulonglong(va_list ap, t_list_arg *list)
{
	list->arg.type = ULONGLONG;
	list->arg.u_arg.u = va_arg(ap, unsigned long long);
}
