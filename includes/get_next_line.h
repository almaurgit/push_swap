/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:15:48 by amaurel           #+#    #+#             */
/*   Updated: 2018/09/30 12:56:56 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"
# define BUFF_SIZE 4096

char	*ft_realloc(char **src, size_t addsize);
int		copy_line(char **line, char **stock);
int		get_next_line(int fd, char **line);

#endif
