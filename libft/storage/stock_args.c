/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:50:43 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/23 14:48:45 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type			g_typetab[] =
{
	{CHAR, &ft_stock_char},
	{SHORT, &ft_stock_short},
	{INT, &ft_stock_int},
	{LONG, &ft_stock_long},
	{LONGLONG, &ft_stock_longlong},

	{UCHAR, &ft_stock_uchar},
	{USHORT, &ft_stock_ushort},
	{UINT, &ft_stock_uint},
	{ULONG, &ft_stock_ulong},
	{ULONGLONG, &ft_stock_ulonglong},

	{SIZE_T, &ft_stock_size_t},

	{INTMAX_T, &ft_stock_intmax_t},
	{UINTMAX_T, &ft_stock_uintmax_t},

	{DOUBLE, &ft_stock_double},

	{PTR_VOID, &ft_stock_ptr},

	{STRING, &ft_stock_string},
	{PTR_INT, &ft_stock_ptr_int},

	{WINT_T, &ft_stock_wint_t},
	{STR_WCHAR_T, &ft_stock_str_wchar_t},

	{0, &ft_stock_usage}
};

t_list_arg	*create_list_args(int type, va_list ap)
{
	t_list_arg	*new;
	int			i;

	i = 0;
	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	while (g_typetab[i].type > 0)
	{
		if (type == g_typetab[i].type)
		{
			g_typetab[i].ft_type(ap, new);
			break ;
		}
		i++;
	}
	new->next = NULL;
	return (new);
}

int			add_list_args(t_list_arg *list, int type, va_list ap)
{
	t_list_arg	*tmp;
	int			i;

	tmp = list;
	i = 0;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = malloc(sizeof(*tmp))))
			return (0);
		while (g_typetab[i].type > 0)
		{
			if (type == g_typetab[i].type)
			{
				g_typetab[i].ft_type(ap, tmp->next);
				break ;
			}
			i++;
		}
		tmp->next->next = NULL;
	}
	return (1);
}

t_list_arg	*stock_args(t_list_conv *listconv, va_list ap)
{
	t_list_arg	*list;
	int			i;

	list = NULL;
	i = 0;
	if (listconv && (is_flag_dollar(listconv)))
		return (valid_dollar(listconv) ? stock_args_dollar(listconv, ap) : 0);
	while (listconv)
	{
		asterisk(&(listconv->conv), ap);
		if (list == NULL)
		{
			if (!(list = create_list_args(listconv->conv.type, ap)))
				return (NULL);
		}
		else
		{
			if (!(add_list_args(list, listconv->conv.type, ap)))
				return (NULL);
		}
		listconv = listconv->next;
	}
	return (list);
}
