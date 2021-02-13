/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:10:32 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:10:35 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_nlen(int n)
{
	size_t	i;

	i = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*ft_itoa_bis(int n, int neg, int size, char *nbr)
{
	if (n < 0 && neg == 0)
	{
		n = -n;
		neg = 1;
		nbr[0] = '-';
	}
	if (n >= 10 && size >= 0)
	{
		nbr[size] = (n % 10) + '0';
		return (ft_itoa_bis(n / 10, neg, size - 1, nbr));
	}
	if (size >= neg)
		nbr[size] = n + '0';
	return (nbr);
}

char			*ft_itoa(int n)
{
	size_t	size;
	char	*nbr;

	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nlen(n);
	if (n < 0)
		size++;
	if (!(nbr = ft_strnew(size + 1)))
		return (NULL);
	return (ft_itoa_bis(n, 0, size, nbr));
}
