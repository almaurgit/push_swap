/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atointmax_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 12:11:38 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 12:31:57 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

intmax_t	ft_atointmax_t(const char *str)
{
	int			i;
	intmax_t	s;
	intmax_t	nb;

	i = 0;
	s = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		str[i] == '-' ? s = -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (10 * nb) + (str[i] - '0');
		i++;
	}
	return (s * nb);
}
