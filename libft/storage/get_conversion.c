/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:38:35 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/30 14:03:06 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_list_conv	*create_list(char *conversion)
{
	t_list_conv	*new;
	int			i;

	i = 0;
	if (!conversion)
		return (NULL);
	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	while (conversion[i + 1])
		i++;
	new->conv.pos = 1;
	new->conv.char_conv = conversion[i];
	new->conv.conversion = conversion;
	new->conv.id_flags = 0;
	get_ft_conv(&(new->conv));
	if ((get_flags(&(new->conv))) < 1)
		return (0);
	get_type(&(new->conv));
	new->next = NULL;
	return (new);
}

static	int			add_list(t_list_conv *list, char *conv)
{
	t_list_conv *tmp;
	int			i;

	i = 0;
	tmp = list;
	if (!conv)
		return (0);
	if (!tmp)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(*tmp))))
		return (0);
	while (conv[i + 1])
		i++;
	tmp->next->conv.pos = tmp->conv.pos + 1;
	tmp->next->conv.char_conv = conv[i];
	tmp->next->conv.conversion = conv;
	tmp->next->conv.id_flags = 0;
	get_ft_conv(&(tmp->next->conv));
	if (get_flags(&(tmp->next->conv)) < 1)
		return (0);
	get_type(&(tmp->next->conv));
	tmp->next->next = NULL;
	return (1);
}

static	char		*conversion(char *format, int *index)
{
	char	*conv;
	int		i;
	int		k;

	k = 0;
	(*index)++;
	i = *index;
	if (!format || format == '\0' || !index || !(*index))
		return (NULL);
	while (is_flags(format[*index]))
		(*index)++;
	if (!is_conv(format[*index]))
		return (NULL);
	if (!(conv = malloc(sizeof(char) * (*index - i + 1))))
		return (NULL);
	while (i <= *index)
	{
		conv[k] = format[i];
		i++;
		k++;
	}
	conv[k] = '\0';
	return (conv);
}

int					list_conv(t_list_conv **list, char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (*list == NULL)
			{
				if (!(*list = create_list(conversion(format, &i))))
					return (-1);
			}
			else if (!(add_list(*list, conversion(format, &i))))
				return (-1);
		}
		i++;
	}
	if (!(*list))
		return (0);
	return (1);
}
