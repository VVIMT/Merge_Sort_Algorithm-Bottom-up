/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:13:14 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:13:17 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (x[i] != y[i])
			return (x[i] - y[i]);
		i++;
	}
	return (0);
}
