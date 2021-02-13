/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:11:08 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:11:11 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_alst;

	if (*alst)
		tmp_alst = *alst;
	while (*alst)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		tmp_alst = (*alst)->next;
		(*alst)->next = NULL;
		*alst = tmp_alst;
	}
	tmp_alst = NULL;
}
