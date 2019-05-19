/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 03:26:20 by amaurel           #+#    #+#             */
/*   Updated: 2018/10/13 11:56:16 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char **src, size_t addsize)
{
	char	*new;
	size_t	len;

	new = NULL;
	if (!src)
		return (NULL);
	len = ft_strlen(*src);
	if (addsize <= 0)
		return (*src);
	if (!(new = ft_memalloc(len + addsize + 1)))
		return (NULL);
	ft_memmove(new, *src, len + addsize);
	free(*src);
	return (new);
}

int		copy_line(char **line, char **stock)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(*stock);
	while ((*stock)[i] != '\n' && (*stock)[i])
		i++;
	if (!(*line = ft_memalloc((i + 1))))
		return (0);
	ft_memcpy(*line, *stock, i);
	(*line)[i] = '\0';
	tmp = *stock;
	if (!(*stock = (*stock)[i] == '\n' ? ft_strdup(*stock + i + 1) :
	ft_strdup(*stock + i)))
		return (0);
	free(tmp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*stock[OPEN_MAX];
	char			*buf;
	int				ret;

	if (fd < 0 || !line || fd > OPEN_MAX || BUFF_SIZE < 1)
		return (-1);
	if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if (!stock[fd])
		if (!(stock[fd] = ft_memalloc(BUFF_SIZE + 1)))
			return (-1);
	while (!ft_strchr(stock[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(stock[fd] = ft_realloc(&stock[fd], BUFF_SIZE)))
			return (-1);
		ft_strcat(stock[fd], buf);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	free(buf);
	if (!stock[fd][0] && !ret)
		return (0);
	if (!copy_line(line, &(stock[fd])))
		return (-1);
	return (ret < 0 ? -1 : 1);
}
