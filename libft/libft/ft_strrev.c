/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:10:05 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/15 15:33:45 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	size_t	len;
	size_t	i;
	char	*rev;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(rev = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		rev[i] = s[len - i - 1];
		i++;
	}
	rev[len] = '\0';
	return (rev);
}
