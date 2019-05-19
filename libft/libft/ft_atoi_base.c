/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:15:36 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/15 15:55:46 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_err(const char *base, size_t lenbase)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (lenbase <= 1)
		return (1);
	while (i < lenbase)
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (1);
		while (j < lenbase)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int		ft_spec(const char *str)
{
	int k;
	int sign;

	k = 0;
	sign = 1;
	while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n'
			|| str[k] == '\r' || str[k] == '\v' || str[k] == '\f')
		k++;
	if (str[k] == '-')
	{
		k++;
		sign = -1;
	}
	if (str[k] == '+')
		k++;
	return (k * sign);
}

static int		ft_ret(const char *str, const char *base, int lenbase, int k)
{
	size_t	i;
	size_t	j;
	size_t	n;
	int		ret;

	i = 0;
	ret = 0;
	while (str[k + i] && str[k + i] != '+' && str[k + i] != '-')
	{
		j = 0;
		n = 0;
		while (base[j])
		{
			if (str[k + i] == base[j])
				ret = ret * lenbase + j;
			if (str[k + i] != base[j] && str[k + i] != '-' && str[k + i] != '+')
				n++;
			j++;
		}
		if (j == n)
			return (0);
		i++;
	}
	return (ret);
}

int				ft_atoi_base(const char *str, const char *base)
{
	size_t	lenbase;
	int		n;
	int		err;
	int		sign;
	int		k;

	if (!str || !base || !(*str))
		return (0);
	n = 0;
	sign = 1;
	lenbase = ft_strlen(base);
	err = ft_err(base, lenbase);
	k = ft_spec(str);
	k < 0 ? (sign = -1) : 1;
	if (!err)
		n = ft_ret(str, base, lenbase, sign * k);
	return (sign * n);
}
