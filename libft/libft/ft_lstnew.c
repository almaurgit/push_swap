/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:20:04 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/13 18:42:28 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	list = NULL;
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		list->content = malloc(content_size);
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
		list->next = NULL;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	return (list);
}
