/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:44:13 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/21 04:57:30 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_l(t_conversion *conv)
{
	char c;

	c = conv->char_conv;
	if (c == 'd' || c == 'i')
		conv->type = LONG;
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
		conv->type = ULONG;
	else if (c == 'n')
		conv->type = PTR_INT;
	else if (c == 'a' || c == 'A' || c == 'f' || c == 'F')
		conv->type = DOUBLE;
	else if (c == 'c')
		conv->type = WINT_T;
	else if (c == 's')
		conv->type = STR_WCHAR_T;
	else
		get_no_mod(conv);
}

void	get_ll(t_conversion *conv)
{
	char c;

	c = conv->char_conv;
	if (c == 'd' || c == 'i')
		conv->type = LONGLONG;
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
		conv->type = ULONGLONG;
	else if (c == 'n')
		conv->type = PTR_INT;
	else
		get_no_mod(conv);
}

void	get_j(t_conversion *conv)
{
	char c;

	c = conv->char_conv;
	if (c == 'd' || c == 'i')
		conv->type = INTMAX_T;
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
		conv->type = UINTMAX_T;
	else if (c == 'n')
		conv->type = PTR_INT;
	else
		get_no_mod(conv);
}

void	get_z(t_conversion *conv)
{
	char c;

	c = conv->char_conv;
	if (c == 'd' || c == 'i')
		conv->type = ULONG;
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
		conv->type = SIZE_T;
	else if (c == 'n')
		conv->type = PTR_INT;
	else
		get_no_mod(conv);
}
