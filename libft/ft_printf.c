/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:58:27 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 16:38:14 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	delete_arg(t_list_arg *arg)
{
	t_list_arg	*argtmp;
	t_list_arg	*argtemp;

	if (arg)
	{
		argtmp = arg;
		while (argtmp)
		{
			argtemp = argtmp->next;
			free(argtmp);
			argtmp = argtemp;
		}
	}
}

static	void	delete_all
	(t_buffer *buffer, t_list_conv *list, t_list_arg *arg)
{
	t_list_conv	*tmp;
	t_list_conv *temp;

	free(buffer->buf);
	if (list)
	{
		tmp = list;
		while (tmp)
		{
			temp = tmp->next;
			free(tmp->conv.conversion);
			free(tmp->conv.pad);
			free(tmp->conv.mod);
			free(tmp);
			tmp = temp;
		}
	}
	delete_arg(arg);
}

static	int		ft_printf_bis
	(const char *format, va_list ap, t_list_conv *l_conv, t_list_arg *l_arg)
{
	int			ret;
	t_buffer	buffer;

	buffer.buf = NULL;
	buffer.ind = 0;
	if ((ret = list_conv(&l_conv, (char *)format)) == -1)
	{
		delete_all(&buffer, l_conv, l_arg);
		return (-1);
	}
	if (ret && !(l_arg = stock_args(l_conv, ap)))
	{
		delete_all(&buffer, l_conv, l_arg);
		return (-1);
	}
	if (!get_buffer(format, &buffer, l_conv, l_arg))
	{
		delete_all(&buffer, l_conv, l_arg);
		return (-1);
	}
	write(1, buffer.buf, buffer.ind);
	ret = buffer.ind;
	delete_all(&buffer, l_conv, l_arg);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_list_conv	*liste_conversions;
	t_list_arg	*liste_arguments;
	int			ret;

	va_start(ap, format);
	liste_conversions = NULL;
	liste_arguments = NULL;
	ret = ft_printf_bis(format, ap, liste_conversions, liste_arguments);
	va_end(ap);
	return (ret);
}
