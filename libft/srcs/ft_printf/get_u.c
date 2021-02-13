/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:59:31 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/29 22:28:32 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_u(t_types *t, uintmax_t u)
{
	t->u = u;
	t->tmp = ft_itoa_base_u(u, 10, 0);
	t->x = ft_strlen(t->tmp);
	if (t->precision >= 0 && t->precision > t->x)
		t->x = t->precision;
	t->str = ft_strnew(t->x + 1);
	ft_bzero(t->str, t->x + 1);
	t->y = ft_strlen(t->tmp);
	while (--t->y >= 0)
		t->str[--t->x] = t->tmp[t->y];
	while (--t->x >= 0)
		t->str[t->x] = '0';
	(t->tmp ? free(t->tmp) : t->tmp);
	t->x = ft_strlen(t->str);
	if ((size_t)(t->width) > ft_strlen(t->str))
		t->x = t->width;
	if (u == 0 && t->width == 0 && t->precision == 0)
		t->x = 0;
	t->tmp = ft_strnew(t->x + 1);
	ft_bzero(t->tmp, t->x + 1);
	t->ret = t->x;
	flag_field_u(t);
	write(1, t->str, t->ret);
	(t->str ? free(t->str) : t->str);
	return (t->ret);
}

void	flag_field_u(t_types *t)
{
	ft_memset(t->tmp, ' ', t->x);
	if (t->sig3 > 0 && t->sig2 == 0 && t->precision < 0)
		ft_memset(t->tmp, '0', t->x);
	if (t->sig2 == 0 && (t->u != 0 || t->precision != 0))
	{
		t->y = ft_strlen(t->str);
		while (--(t->y) >= 0)
			t->tmp[--t->x] = t->str[t->y];
	}
	else if (t->sig2 > 0 && (t->u != 0 || t->precision != 0))
	{
		t->x = 0;
		t->y = 0;
		while (t->str[t->y])
			t->tmp[t->x++] = t->str[t->y++];
	}
	(t->str ? free(t->str) : t->str);
	t->str = t->tmp;
}
