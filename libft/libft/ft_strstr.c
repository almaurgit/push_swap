/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:17:07 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/09 21:09:28 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*s;
	size_t	i;

	i = 0;
	s = ft_strchr(haystack, needle[0]);
	while (s != NULL && *s)
	{
		i = 0;
		while (s[i] == needle[i] && needle[i])
			i++;
		if (i == ft_strlen(needle))
			return (s);
		else
			s = ft_strchr(++s, needle[0]);
	}
	if (!s)
		return (NULL);
	return ((char *)haystack);
}
