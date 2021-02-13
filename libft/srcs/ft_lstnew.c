/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:12:12 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:12:16 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		list->content_size = content_size;
		list->content = ft_memalloc(content_size);
		ft_memcpy(list->content, content, content_size);
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
