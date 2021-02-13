/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:01:34 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/29 22:27:18 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_o(t_types *t, uintmax_t oct)
{
	t->oct = oct;
	t->tmp = ft_itoa_base_u(oct, 8, 0);
	t->x = ft_strlen(t->tmp);
	(oct != 0 && t->sig4 > 0 && t->width <= t->x) ? t->x++ : t->x;
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
	if (t->sig4 == 0 && oct == 0 && t->width == 0 && t->precision == 0)
		t->x = 0;
	t->tmp = ft_strnew(t->x + 1);
	ft_bzero(t->tmp, t->x + 1);
	t->ret = t->x;
	flag_field_o(t);
	write(1, t->str, t->ret);
	(t->str ? free(t->str) : t->str);
	return (t->ret);
}

void	flag_field_o(t_types *t)
{
	ft_memset(t->tmp, ' ', t->x);
	if (t->sig3 > 0 && t->sig2 == 0 && t->precision < 0)
		ft_memset(t->tmp, '0', t->x);
	if (t->sig2 == 0 && (t->sig4 != 0 || t->oct != 0 || t->precision != 0))
	{
		t->y = ft_strlen(t->str);
		while (--(t->y) >= 0)
			t->tmp[--t->x] = t->str[t->y];
		t->x = ft_strlen(t->tmp);
		while (t->sig4 > 0 && t->oct > 0 && t->x > 0 && t->tmp[t->x--] != ' ')
			if ((t->tmp[t->x] == ' ' && t->tmp[t->x + 1] != '0') || t->x == 0)
				t->tmp[t->x--] = '0';
	}
	else if (t->sig2 > 0 && (t->sig4 != 0 || t->oct != 0 || t->precision != 0))
	{
		t->x = 0;
		(t->sig4 > 0 && t->oct > 0 && t->str[0] != '0') ? t->tmp[0] = '0' : 1;
		(t->sig4 > 0 && t->oct > 0 && t->str[0] != '0') ? t->x++ : 1;
		t->y = 0;
		while (t->str[t->y])
			t->tmp[t->x++] = t->str[t->y++];
	}
	(t->str ? free(t->str) : t->str);
	t->str = t->tmp;
}
