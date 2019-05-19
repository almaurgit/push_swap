/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_putbuffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 03:36:19 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 18:28:28 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_realloc(char **buffer, int *ind)
{
	char	*new;

	new = malloc(sizeof(char *) * (*ind + BUFF_SIZE + 1));
	if (new == NULL)
		return (0);
	if (*buffer)
		new = ft_memmove(new, *buffer, *ind);
	if (*buffer)
		free(*buffer);
	new[*ind + BUFF_SIZE + 1] = '\0';
	return (new);
}

int				ft_putbuffer(char c, t_buffer *buffer)
{
	if (buffer->ind % BUFF_SIZE == 0)
		if (!(buffer->buf = ft_realloc(&(buffer->buf), &(buffer->ind))))
			return (0);
	(buffer->buf)[(buffer->ind)++] = c;
	return (1);
}

int				ft_putstr_buff(char *s, t_buffer *buffer)
{
	while (*s)
		if (!(ft_putbuffer(*s++, buffer)))
			return (0);
	return (1);
}
