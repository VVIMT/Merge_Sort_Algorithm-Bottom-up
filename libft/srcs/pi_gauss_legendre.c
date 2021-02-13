/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_gauss_legendre.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:51:45 by vinvimo           #+#    #+#             */
/*   Updated: 2019/01/30 20:20:21 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

long double		pi_gauss_legendre(long double pi, int precision)
{
	long double a;
	long double b;
	long double t;
	long double p;
	long double tmp;

	a = 1;
	b = 1 / sqrtl(2);
	t = 1 / (long double)4;
	p = 1;
	while (precision > 0)
	{
		tmp = a;
		a = (a + b) / 2;
		b = sqrtl(tmp * b);
		t = t - (p * powl(tmp - a, 2));
		p = 2 * p;
		precision--;
	}
	pi = (powl(a + b, 2)) / (4 * t);
	return (pi);
}
