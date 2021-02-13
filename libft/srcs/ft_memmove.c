/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:14:04 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:14:07 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	const	*x;

	x = dst;
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			*((unsigned char *)x + len) = *((unsigned char *)src + len);
		}
	}
	else if (dst < src)
	{
		while (len > 0)
		{
			*((unsigned char *)x++) = *((unsigned char *)src++);
			len--;
		}
	}
	return (dst);
}
