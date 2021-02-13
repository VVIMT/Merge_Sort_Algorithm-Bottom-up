/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:00:11 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/20 00:00:14 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_c(t_types *t, wchar_t c, int i)
{
	unicode_to_utf8(c, NULL, &i);
	t->ret = i;
	if (t->width <= i)
	{
		i = 0;
		ft_putstr_w(unicode_to_utf8(c, NULL, &i));
		if (!c)
			ft_putchar(0);
	}
	else
		c_in_tab(t, c, &i);
	if (t->upper_dst)
		free(t->upper_dst);
	if (t->width > t->ret)
		return (t->width);
	return (i);
}

void	c_in_tab(t_types *t, wchar_t c, int *i)
{
	t->upper_dst = ft_strnew_w(t->width - *i + 1);
	ft_memset_w(t->upper_dst, 0, t->width - *i + 1);
	if (t->sig3 > 0)
		ft_memset_w(t->upper_dst, '0', t->width - *i);
	else
		ft_memset_w(t->upper_dst, ' ', t->width - *i);
	if (t->sig2 > 0)
	{
		(c ? ft_putstr_w(unicode_to_utf8(c, NULL, i)) : ft_putchar(0));
		ft_putstr_w(t->upper_dst);
	}
	else
	{
		ft_putstr_w(t->upper_dst);
		(c ? ft_putstr_w(unicode_to_utf8(c, NULL, i)) : ft_putchar(0));
	}
}
