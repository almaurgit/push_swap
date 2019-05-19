/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:04:31 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/14 15:11:37 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_negative(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
	return (0);
}

char				*ft_itoa(int n)
{
	char			*nb;
	int				i;
	int				k;
	unsigned int	un;

	i = 0;
	k = 0;
	un = ft_negative(n);
	if (n < 0)
		i++;
	while (un >= 10 && ++i)
		un /= 10;
	if (!(nb = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	un = ft_negative(n);
	while (un >= 10)
	{
		nb[i - k] = (un % 10) + '0';
		un /= 10;
		k++;
	}
	nb[i - k] = (un % 10) + '0';
	nb[i + 1] = '\0';
	n < 0 ? nb[0] = '-' : 1;
	return (nb);
}
