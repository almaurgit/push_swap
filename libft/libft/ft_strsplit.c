/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:02:25 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/14 11:51:16 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbwords(char const *s, char c)
{
	size_t	i;
	int		nb;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			nb++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static int	*nbchars(char const *s, char c, int n)
{
	int		*nbl;
	size_t	j;
	size_t	i;
	int		nbc;

	i = 0;
	j = 0;
	if (!(nbl = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (s[i])
	{
		nbc = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			nbc++;
			i++;
		}
		nbl[j] = nbc;
		j++;
	}
	return (nbl);
}

static char	**fill(char **split, char const *s, char c)
{
	int i;
	int k;

	k = 0;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			split[k][i] = *s++;
			i++;
		}
		k++;
	}
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nbw;
	int		*nbl;
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	nbw = nbwords(s, c);
	nbl = nbchars(s, c, nbw);
	if (!(split = (char **)malloc(sizeof(char *) * (nbw + 1))))
		return (NULL);
	split[nbw] = 0;
	while (i < nbw)
	{
		if (!(split[i] = (char *)malloc(sizeof(char) * (nbl[i] + 1))))
			return (NULL);
		split[i][nbl[i]] = '\0';
		i++;
	}
	split = fill(split, s, c);
	return (split);
}
