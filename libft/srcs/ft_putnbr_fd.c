/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:16:19 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:16:21 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr_min_fd(int n, int *fd)
{
	int	x;

	x = *fd;
	ft_putnbr_fd(n, x);
	ft_putchar_fd('8', x);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putnbr_min_fd(-214748364, &fd);
	if (n >= -2147483647 && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
