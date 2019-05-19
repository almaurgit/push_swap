/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:53:43 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/23 13:26:02 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_no_mod(t_conversion *conv)
{
	char c;

	c = conv->char_conv;
	if (c == 'd' || c == 'i' || c == 'c')
		conv->type = INT;
	else if (c == 'D')
		conv->type = LONG;
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
		conv->type = UINT;
	else if (c == 'O' || c == 'U')
		conv->type = ULONG;
	else if (c == 'a' || c == 'A' || c == 'f' || c == 'F')
		conv->type = DOUBLE;
	else if (c == 's')
		conv->type = STRING;
	else if (c == 'C')
		conv->type = WINT_T;
	else if (c == 'S')
		conv->type = STR_WCHAR_T;
	else if (c == 'p')
		conv->type = PTR_VOID;
	else if (c == 'n')
		conv->type = PTR_INT;
	else if (c == '%')
		conv->type = PERCENT;
}

void	get_hh(t_conversion *conv)
{
	char c;

	c = conv->char_conv;
	if (c == 'd' || c == 'i')
		conv->type = CHAR;
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
		conv->type = UCHAR;
	else if (c == 'n')
		conv->type = PTR_INT;
	else
		get_no_mod(conv);
}

void	get_h(t_conversion *conv)
{
	char c;

	c = conv->char_conv;
	if (c == 'd' || c == 'i')
		conv->type = SHORT;
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
		conv->type = USHORT;
	else if (c == 'n')
		conv->type = PTR_INT;
	else
		get_no_mod(conv);
}
