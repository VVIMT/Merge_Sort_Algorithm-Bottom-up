/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:18:22 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:18:24 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (x[i] - y[i]);
		i++;
	}
	return (0);
}
