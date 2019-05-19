/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_stock_args4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:43:09 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:38:33 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stock_string(va_list ap, t_list_arg *list)
{
	list->arg.type = STRING;
	list->arg.u_arg.s = va_arg(ap, char *);
}

void	ft_stock_ptr_int(va_list ap, t_list_arg *list)
{
	list->arg.type = PTR_INT;
	list->arg.u_arg.n = va_arg(ap, int *);
}

void	ft_stock_wint_t(va_list ap, t_list_arg *list)
{
	list->arg.type = WINT_T;
	list->arg.u_arg.wc = va_arg(ap, wint_t);
}

void	ft_stock_str_wchar_t(va_list ap, t_list_arg *list)
{
	list->arg.type = STR_WCHAR_T;
	list->arg.u_arg.ws = va_arg(ap, wchar_t *);
}

void	ft_stock_usage(va_list ap, t_list_arg *list)
{
	if (ap || list)
		;
	return ;
}
