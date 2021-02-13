/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:14:44 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:25:43 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_power(long double x, int y)
{
	float	result;

	result = 1;
	if (y == 0)
		return (1);
	while (y > 0)
	{
		result = result * x;
		y--;
	}
	return (result);
}
