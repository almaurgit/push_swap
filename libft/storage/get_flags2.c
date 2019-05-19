/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:23:21 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/26 17:17:20 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		id_padding(char *pad)
{
	int		id_pad;
	int		i;

	i = 0;
	id_pad = 0;
	while (pad[i])
	{
		if (pad[i] == '#')
			id_pad = id_pad | HASHTAG;
		else if (pad[i] == '0')
			id_pad = id_pad | ZERO;
		else if (pad[i] == ' ')
			id_pad = id_pad | SPACE;
		else if (pad[i] == '-')
			id_pad = id_pad | MOINS;
		else if (pad[i] == '+')
			id_pad = id_pad | PLUS;
		else if (pad[i] == '\'')
			id_pad = id_pad | APOSTROPHE;
		i++;
	}
	return (id_pad);
}

static	int		get_new_pos(char *conv, int *i)
{
	int		pos;

	pos = 0;
	while (conv[*i] >= '0' && conv[*i] <= '9')
	{
		pos = pos * 10 + (conv[*i] - '0');
		(*i)++;
	}
	(*i)++;
	return (pos);
}

static	int		get_pos(t_conversion *conv, int *i)
{
	int j;

	j = *i;
	while ((conv->conversion[j] >= '0') && (conv->conversion[j] <= '9'))
		j++;
	if (conv->conversion[j] == '$')
	{
		conv->id_flags = conv->id_flags | FLAG_DOLLAR;
		return (get_new_pos(conv->conversion, i));
	}
	else
		return (conv->pos);
	return (-1);
}

static	int		get_flags_bis(t_conversion *conv, int index, int ret)
{
	if (conv->conversion[index] == '.')
	{
		index++;
		conv->prec = get_precision(conv->conversion, &index);
		conv->prec >= 0 || conv->prec == -2 ?
		conv->id_flags |= PRECISION : (ret = -1);
		conv->prec == -2 ? conv->id_flags |= PRECISION_ASTERISK | PRECISION : 1;
	}
	conv->mod = get_modifyer(conv->conversion, &index);
	valid_modifyer(conv->mod) ? 1 : (ret = -1);
	*(conv->mod) ? conv->id_flags = conv->id_flags | MODIFYER : 1;
	return (ret >= 0 && conv->conversion[index] == conv->char_conv ? 1 : ret);
}

int				get_flags(t_conversion *conv)
{
	int		index;
	int		ret;

	index = 0;
	ret = 0;
	conv->id_flags = 0;
	conv->pos = get_pos(conv, &index);
	conv->pos == -1 ? (ret = -1) : 1;
	conv->pad = get_padding(conv->conversion, &index);
	conv->id_pad = id_padding(conv->pad);
	*(conv->pad) ? conv->id_flags |= PADDING : 1;
	conv->width = get_fieldwidth(conv->conversion, &index);
	conv->width >= 0 || conv->width == -2 ? 1 : (ret = -1);
	conv->width > 0 ? conv->id_flags |= FIELD_WIDTH : 1;
	conv->width == -2 ? conv->id_flags |= WIDTH_ASTERISK | FIELD_WIDTH : 1;
	return (get_flags_bis(conv, index, ret));
}
