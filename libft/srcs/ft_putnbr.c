/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:16:06 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:16:08 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr_min(int n)
{
	ft_putnbr(n);
	ft_putchar('8');
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putnbr_min(-214748364);
	if (n >= -2147483647 && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
