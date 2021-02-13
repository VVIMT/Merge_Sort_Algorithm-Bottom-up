/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:19:42 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:19:44 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			(*f)(index, s + i);
			index++;
			i++;
		}
	}
}
