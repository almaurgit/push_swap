/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:38:58 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/15 15:43:30 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base_int(const char *n, int base_from, int base_to)
{
	char	*res;
	char	*base;
	char	*basedup;
	int		i;

	i = 0;
	if (!(base_from > 1 && base_from <= 16 && base_to > 1 && base_from <= 16))
		return (0);
	if (!(base = (char *)malloc(sizeof(char) * 17)) || !n)
		return (NULL);
	while (i < 10)
	{
		base[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		base[i] = i + 'A' - 10;
		i++;
	}
	basedup = ft_strdup(base);
	base[base_from] = '\0';
	basedup[base_to] = '\0';
	res = ft_convert_base(n, base, basedup);
	return (res);
}
