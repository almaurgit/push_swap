/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:30:09 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/15 15:38:37 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(const char *nb, const char *base_from,
		const char *base_to)
{
	int		n;

	if (!nb || !base_from || !base_to)
		return (NULL);
	n = ft_atoi_base(nb, base_from);
	return (ft_itoa_base(n, base_to));
}
