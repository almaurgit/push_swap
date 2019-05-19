/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_stock_args3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:42:12 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:43:10 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stock_size_t(va_list ap, t_list_arg *list)
{
	list->arg.type = SIZE_T;
	list->arg.u_arg.u = va_arg(ap, size_t);
}

void	ft_stock_intmax_t(va_list ap, t_list_arg *list)
{
	list->arg.type = INTMAX_T;
	list->arg.u_arg.d = va_arg(ap, intmax_t);
}

void	ft_stock_uintmax_t(va_list ap, t_list_arg *list)
{
	list->arg.type = UINTMAX_T;
	list->arg.u_arg.u = va_arg(ap, uintmax_t);
}

void	ft_stock_double(va_list ap, t_list_arg *list)
{
	list->arg.type = DOUBLE;
	list->arg.u_arg.f = va_arg(ap, double);
}

void	ft_stock_ptr(va_list ap, t_list_arg *list)
{
	list->arg.type = PTR_VOID;
	list->arg.u_arg.p = va_arg(ap, void *);
}
