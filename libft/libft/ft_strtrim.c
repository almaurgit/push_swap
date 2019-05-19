/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:58:26 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/14 13:56:01 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*fill(char *ret, const char *s, size_t size, size_t i_start)
{
	size_t	i;

	i = -1;
	while (++i < size)
		ret[i] = s[i_start + i];
	ret[i] = '\0';
	return (ret);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	i_start;
	size_t	i_end;
	char	*ret;
	int		len;

	i = 0;
	ret = NULL;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (!s[i])
		return (ft_strdup(""));
	i_start = i;
	i = 1;
	while (s[len - i] == ' ' || s[len - i] == '\t' || s[len - i] == '\n')
		i++;
	i_end = i - 1;
	ret = (char *)malloc(sizeof(char) * (len - i_start - i_end + 1));
	if (ret == NULL)
		return (NULL);
	ret = fill(ret, s, len - i_start - i_end, i_start);
	return (ret);
}
