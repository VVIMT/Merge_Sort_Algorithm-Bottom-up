/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:12:58 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:13:01 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	const	*x;

	x = s;
	while (n > 0)
	{
		n--;
		if (*x == (unsigned char)c)
			return ((void *)x);
		x++;
	}
	return (NULL);
}
