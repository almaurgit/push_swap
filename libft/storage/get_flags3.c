/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 04:30:46 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/23 13:25:20 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_padding(char *conv, int *i)
{
	char	*pad;
	int		k;
	int		j;

	k = 0;
	j = *i;
	while (conv[*i] == '#' || conv[*i] == '0' || conv[*i] == '-'
			|| conv[*i] == ' ' || conv[*i] == '+' || conv[*i] == '\'')
	{
		k++;
		(*i)++;
	}
	if (!(pad = malloc(sizeof(char) * (k + 1))))
		return (NULL);
	k = 0;
	while (j < *i)
	{
		pad[k] = conv[j];
		k++;
		j++;
	}
	pad[k] = '\0';
	return (pad);
}

int		get_fieldwidth(char *conv, int *i)
{
	int		wid;

	wid = 0;
	while (conv[*i] >= '0' && conv[*i] <= '9')
	{
		wid = wid * 10 + (conv[*i] - '0');
		(*i)++;
	}
	if (conv[*i] == '*')
	{
		(*i)++;
		return (-2);
	}
	return (wid);
}

int		get_precision(char *conv, int *i)
{
	int		prec;

	prec = 0;
	while (conv[*i] >= '0' && conv[*i] <= '9')
	{
		prec = prec * 10 + (conv[*i] - '0');
		(*i)++;
	}
	if (conv[*i] == '*')
	{
		(*i)++;
		return (-2);
	}
	return (prec);
}

char	*get_modifyer(char *conv, int *i)
{
	char	*mod;
	int		k;
	int		j;

	k = 0;
	j = *i;
	while (conv[*i] == 'h' || conv[*i] == 'l' || conv[*i] == 'j'
			|| conv[*i] == 'z' || conv[*i] == 'L')
	{
		k++;
		(*i)++;
	}
	if (!(mod = malloc(sizeof(char) * (k + 1))))
		return (NULL);
	k = 0;
	while (j < *i)
	{
		mod[k] = conv[j];
		k++;
		j++;
	}
	mod[k] = '\0';
	return (mod);
}

int		valid_modifyer(char *mod)
{
	if (!(*mod))
		return (1);
	if (ft_strcmp(mod, "l") && ft_strcmp(mod, "ll")
			&& ft_strcmp(mod, "h") && ft_strcmp(mod, "hh")
			&& ft_strcmp(mod, "j") && ft_strcmp(mod, "z"))
		return (0);
	return (1);
}
