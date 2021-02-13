/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:59:16 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/29 22:24:05 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_d(t_types *t, intmax_t d)
{
	t->d = d;
	d = (d < 0 ? -d : d);
	t->tmp = ft_itoa_base_u(d, 10, 0);
	t->x = ft_strlen(t->tmp);
	t->x = (t->precision >= 0 && t->precision > t->x) ? t->precision : t->x;
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
	else if ((size_t)(t->width) <= ft_strlen(t->str)
			&& (t->d < 0 || t->sig5 > 0 || (t->d >= 0 && t->sig1 > 0)))
		t->x++;
	t->x = (t->d == 0 && t->width == 0 && t->precision == 0) ? 0 : t->x;
	t->ret = t->x;
	flag_field_d(t);
	write(1, t->str, t->ret);
	(t->str ? free(t->str) : t->str);
	return (t->ret);
}

void	push_right_d(t_types *t)
{
	t->y = ft_strlen(t->str);
	while (--(t->y) >= 0)
		t->tmp[--t->x] = t->str[t->y];
	t->x = ft_strlen(t->tmp);
	while (t->d < 0 && t->x > 0 && t->tmp[t->x--] != '-')
		if (t->tmp[t->x] == ' ' || t->x == 0)
			t->tmp[t->x] = '-';
	while (t->sig1 > 0 && t->d >= 0 && t->x > 0 && t->tmp[t->x--] != '+')
		if (t->tmp[t->x] == ' ' || t->x == 0)
			t->tmp[t->x] = '+';
	while (t->sig5 > 0 && t->d >= 0 && t->x-- > 0)
		if (t->x == 0)
			t->tmp[t->x] = ' ';
}

void	push_left_d(t_types *t)
{
	t->x = 0;
	if (t->sig1 > 0 && t->d >= 0)
	{
		t->tmp[0] = '+';
		t->x++;
	}
	else if (t->sig5 > 0 && t->d >= 0)
	{
		t->tmp[0] = ' ';
		t->x++;
	}
	else if (t->d < 0)
	{
		t->tmp[0] = '-';
		t->x++;
	}
	t->y = 0;
	while (t->str[t->y])
		t->tmp[t->x++] = t->str[t->y++];
}

void	flag_field_d(t_types *t)
{
	t->tmp = ft_strnew(t->x + 1);
	ft_bzero(t->tmp, t->x + 1);
	ft_memset(t->tmp, ' ', t->x);
	if (t->sig3 > 0 && t->sig2 == 0 && t->precision < 0)
		ft_memset(t->tmp, '0', t->x);
	if (t->sig2 == 0 && (t->d != 0 || t->precision != 0))
		push_right_d(t);
	else if (t->sig2 > 0 && (t->d != 0 || t->precision != 0))
		push_left_d(t);
	(t->str ? free(t->str) : t->str);
	t->str = t->tmp;
}
