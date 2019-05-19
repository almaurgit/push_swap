/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:58:00 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/14 11:50:28 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*map;
	t_list	*st;

	list = lst;
	if (list)
	{
		map = ft_lstnew(f(list)->content, f(list)->content_size);
		st = map;
		while (list)
		{
			if (list->next)
				map->next = ft_lstnew(f(list->next)->content,
						f(list->next)->content_size);
			else
				map->next = NULL;
			map = map->next;
			list = list->next;
		}
	}
	else
		return (NULL);
	return (st);
}
