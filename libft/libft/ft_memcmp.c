/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:02:56 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/21 16:04:43 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *ss1;
	char *ss2;

	if (!n)
		return (0);
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while (*ss1 == *ss2 && --n > 0)
	{
		ss1++;
		ss2++;
	}
	return ((unsigned char)*ss1 - (unsigned char)*ss2);
}
