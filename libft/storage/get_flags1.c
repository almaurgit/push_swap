/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:18:01 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/23 13:21:33 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_ft_conv	g_fttab[] =
{
	{"idD", &ft_int},
	{"xX", &ft_hexa},
	{"oO", &ft_oct},
	{"uU", &ft_uns},
	{"p", &ft_point},
	{"c", &ft_char},
	{"s", &ft_str},
	{"C", &ft_wchar},
	{"S", &ft_wstr},
	{"%", &ft_percent},
	{"n", &ft_n},
	{"b", &ft_binary},
	{"aA", &ft_hexfloat},
	{"", &ft_usage}
};

static	t_get_type	g_gettype[] =
{
	{"", &get_no_mod},
	{"hh", &get_hh},
	{"h", &get_h},
	{"l", &get_l},
	{"ll", &get_ll},
	{"j", &get_j},
	{"z", &get_z},
};

void				get_ft_conv(t_conversion *conv)
{
	int i;

	i = 0;
	while (!ft_strchr(g_fttab[i].str, conv->char_conv))
		i++;
	conv->ft_conv = g_fttab[i].ft_conv;
}

int					is_flags(char c)
{
	int		i;
	char	flags[22];

	ft_memcpy(flags, " #*$'.-+0123456789hjlz", 22);
	i = 0;
	while (i < 23)
	{
		if (c == flags[i])
			return (1);
		i++;
	}
	return (0);
}

int					is_conv(char c)
{
	int i;

	i = 0;
	while (ft_strcmp(g_fttab[i].str, "") && !ft_strchr(g_fttab[i].str, c))
		i++;
	if (!ft_strcmp(g_fttab[i].str, ""))
		return (0);
	return (1);
}

void				get_type(t_conversion *conv)
{
	int i;

	i = 0;
	while (ft_strcmp(conv->mod, g_gettype[i].mod))
		i++;
	g_gettype[i].get_type(conv);
}
