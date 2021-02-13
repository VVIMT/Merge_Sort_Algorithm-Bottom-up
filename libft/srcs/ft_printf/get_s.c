/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:01:44 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/20 00:01:47 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_s(t_types *t, char *s, int esc)
{
	if (prepare_tab(t, s, esc) == -1)
		return (t->width);
	t->dst = ft_strnew(t->x + 1);
	ft_bzero(t->dst, t->x + 1);
	if (t->sig3 == 0 || t->sig5 > 0)
		ft_memset(t->dst, ' ', t->x);
	else if (t->sig3 > 0 && t->sig2 == 0)
		ft_memset(t->dst, '0', t->x);
	t->x = -1;
	if (s && t->sig2 > 0)
		while (s[++(t->x)] && t->dst[t->x] && (t->precision)-- != 0)
			t->dst[t->x] = s[t->x];
	else if (s)
	{
		t->x = ft_strlen(s);
		if (t->precision < t->x && t->precision >= 0 && esc == 0)
			t->x = t->precision;
		t->y = ft_strlen(t->dst);
		while (--(t->x) >= 0 && --(t->y) >= 0
		&& ((t->precision)-- != 0 || esc == 1))
			t->dst[t->y] = s[t->x];
	}
	write(1, t->dst, t->ret);
	free(t->dst);
	return (t->ret);
}

int	prepare_tab(t_types *t, char *s, int esc)
{
	if (!s)
	{
		if (t->precision > 6 || t->precision == -1)
			t->precision = 6;
		if (t->width < t->precision)
			t->width = t->precision;
		if (t->sig3 > 0)
			write(1, "000000", t->width - t->precision);
		else
			write(1, "      ", t->width - t->precision);
		write(1, "(null)", t->precision);
		return (-1);
	}
	t->x = ft_strlen(s);
	if (t->precision >= 0 && t->precision < t->x && esc == 0)
		t->x = t->precision;
	if (t->width > t->x)
		t->x = t->width;
	t->ret = t->x;
	return (0);
}
