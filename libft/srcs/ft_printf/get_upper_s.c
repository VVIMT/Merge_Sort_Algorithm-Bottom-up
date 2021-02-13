/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_upper_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:02:08 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/24 11:36:58 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_upper_s(t_types *t, wchar_t *s)
{
	int	i;
	int	j;

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
		return (t->width);
	}
	tab_upper_s(t, s, &i, &j);
	i = -1;
	j = 0;
	while (t->upper_dst[++i])
		ft_putstr_w(unicode_to_utf8(t->upper_dst[i], NULL, &j));
	free(t->upper_dst);
	t->ret = j;
	return (t->ret);
}

void	push_left_s(t_types *t, wchar_t *s, int *i)
{
	t->mem = 0;
	if (t->precision >= 0)
	{
		t->mem = t->precision;
		*i = t->x - t->mem;
	}
	t->x = -1;
	while (s[++t->x] && t->precision != 0)
	{
		t->n = 0;
		unicode_to_utf8(s[t->x], NULL, &(t->n));
		t->precision = t->precision - t->n;
		if (t->mem > 0 && t->precision < 0)
			break ;
		t->upper_dst[t->x] = s[t->x];
	}
	while (--(*i) >= 0)
		t->upper_dst[t->x++] = ' ';
	t->upper_dst[t->x++] = 0;
}

void	push_right_s(t_types *t, wchar_t *s, int *i, int *j)
{
	t->mem = *j;
	if (t->precision >= 0)
	{
		t->y = -1;
		t->n = 0;
		while (s[++t->y] && t->n <= t->precision)
		{
			t->mem = t->n;
			unicode_to_utf8(s[t->y], NULL, &(t->n));
		}
		*i = (t->width > t->mem) ? t->x - t->mem : t->x - t->precision;
	}
	t->x = -1;
	while ((t->sig3 == 0 || t->sig5 > 0) && --(*i) >= 0)
		t->upper_dst[++t->x] = ' ';
	while (t->sig3 > 0 && --(*i) >= 0)
		t->upper_dst[++t->x] = '0';
	t->y = -1;
	t->n = 0;
	while (s[++t->y] && t->n < t->mem)
	{
		unicode_to_utf8(s[t->y], NULL, &(t->n));
		t->upper_dst[++t->x] = s[t->y];
	}
	t->upper_dst[++t->x] = 0;
}

void	tab_upper_s(t_types *t, wchar_t *s, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (s[*i])
		unicode_to_utf8(s[(*i)++], NULL, j);
	t->x = *j;
	if (t->precision >= 0 && t->precision < t->x)
		t->x = t->precision;
	if (t->width > t->x)
		t->x = t->width;
	t->upper_dst = ft_strnew_w(t->x + 1);
	ft_memset_w(t->upper_dst, 0, t->x + 1);
	if (t->sig2 > 0)
	{
		*i = t->x - *j;
		push_left_s(t, s, i);
	}
	else
	{
		*i = t->x - *j;
		push_right_s(t, s, i, j);
	}
}
