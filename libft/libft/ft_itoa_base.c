/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:37:28 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/14 15:29:59 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_neg(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
	return (0);
}

static int			ft_err(const char *base, int nb_base)
{
	int i;
	int j;

	i = 0;
	if (nb_base <= 1)
		return (1);
	while (i < nb_base)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (j < nb_base)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char			*ft_res(int n, const char *base, size_t lenbase, int i)
{
	unsigned int	nb;
	int				k;
	char			*number;

	k = 0;
	if (!(number = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	nb = ft_neg(n);
	while (nb >= lenbase)
	{
		number[i - k] = base[nb % lenbase];
		k++;
		nb /= lenbase;
	}
	number[i - k] = base[nb % lenbase];
	n < 0 ? number[0] = '-' : 1;
	number[i + 1] = '\0';
	return (number);
}

char				*ft_itoa_base(int n, const char *base)
{
	size_t			lenbase;
	unsigned int	nb;
	int				len;

	len = 0;
	lenbase = ft_strlen(base);
	if (!base || !(*base))
		return (NULL);
	if (ft_err(base, lenbase))
		return (0);
	if (n < 0)
		len++;
	nb = ft_neg(n);
	while (nb >= lenbase)
	{
		len++;
		nb /= lenbase;
	}
	return (ft_res(n, base, lenbase, len));
}
