/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:11:53 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:11:56 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*tmp_list;

	if (!(new_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp_list = new_list;
	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp_list->next = (*f)(lst);
		lst = lst->next;
		tmp_list = tmp_list->next;
	}
	return (new_list->next);
}
