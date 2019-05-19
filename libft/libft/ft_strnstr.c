/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:56:11 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/09 22:08:16 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i] && n < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (!(needle[j]) && i + j <= len)
				return ((char *)haystack + i);
		}
		i++;
		n++;
	}
	return (NULL);
}
