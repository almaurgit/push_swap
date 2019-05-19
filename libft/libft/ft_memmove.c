/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:49:36 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/15 14:28:42 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src < dst)
		while (i < len)
		{
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
			i++;
		}
	else if (src == dst)
		return (dst);
	else
		while (len-- > 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	return (dst);
}
