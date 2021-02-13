/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:04:01 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/16 19:04:06 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char	const	*x;
	unsigned char			*y;

	x = src;
	y = dst;
	i = 0;
	while (i < n)
	{
		y[i] = x[i];
		if (x[i] == (unsigned char)c)
			return (y + i + 1);
		i++;
	}
	return (NULL);
}
