/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:12:29 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:12:33 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*x;
	size_t	i;

	if (!(x = (void *)malloc(sizeof(*x) * (size))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		x[i] = 0;
		i++;
	}
	return (x);
}
