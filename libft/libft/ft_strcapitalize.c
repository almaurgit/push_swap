/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:52:41 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/15 15:54:25 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (!str)
		return (NULL);
	if (*str > 96 && *str < 123)
		*str -= 32;
	while (*(str + i) != '\0')
	{
		if (str[i] > 96 && str[i] < 123
				&& !((str[i - 1] < 123 && str[i - 1] > 96)
					|| (str[i - 1] < 91 && str[i - 1] > 64)
					|| (str[i - 1] < 58 && str[i - 1] > 47)))
			str[i] -= 32;
		if (str[i] >= 'A' && str[i] <= 'Z'
				&& ((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
					|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')))
			str[i] += 32;
		i++;
	}
	return (str);
}
