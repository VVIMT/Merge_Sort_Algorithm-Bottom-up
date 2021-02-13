/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:56:20 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/16 19:56:40 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_strnew_w(size_t size)
{
	wchar_t	*x;
	size_t	i;

	if (!(x = (wchar_t *)malloc(sizeof(*x) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		x[i] = 0;
		i++;
	}
	return (x);
}
