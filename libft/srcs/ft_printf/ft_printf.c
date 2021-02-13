/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:59:05 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/29 21:18:16 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	loop(const char *format, va_list *ap, t_types *t, int *ret)
{
	while (1)
	{
		if (format[t->index] == '%')
			*ret = get_s(t, "%", 1);
		else if (var_1(format[t->index], ap, t, ret) >= 0)
			break ;
		else if (var_2(format[t->index], ap, t, ret) >= 0)
			break ;
		else if (var_3(format[t->index], ap, t, ret) >= 0)
			break ;
		else if (var_4(format[t->index], ap, t, ret) >= 0)
			break ;
		else if (var_5(format[t->index], ap, t, ret) >= 0)
			break ;
		else if (var_6(format[t->index], ap, t, ret) >= 0)
			break ;
		break ;
	}
}

size_t	variable(const char *format, va_list *ap, va_list *ap2, t_types *t)
{
	int	ret;

	initialize(t);
	ret = -1;
	t->syntax = 0;
	t->index++;
	t->param = (t->syntax == 0) ? get_param(format, ap2, t) : 0;
	(t->syntax < 2) ? get_flag(format, t) : 1;
	t->width = (t->syntax < 3) ? get_width(format, t) : 0;
	t->precision = (t->syntax < 4) ? get_precision(format, t, -1) : -1;
	t->length = (t->syntax < 5) ? get_length(format, t) : 0;
	if (t->param == 0 || t->param == 2)
		loop(format, ap, t, &ret);
	else if (t->param == 1)
		loop(format, ap2, t, &ret);
	if (format[t->index])
		t->index++;
	if (ret == -1)
		ret = 0;
	return (ret);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	va_list		ap2;
	t_types		t;
	int			ret;

	va_start(ap, format);
	t.count = 0;
	t.index = 0;
	while (format[t.index])
	{
		ret = 0;
		va_copy(ap2, ap);
		if (format[t.index] == '%')
			ret = variable(format, &ap, &ap2, &t);
		else if (format[t.index])
		{
			write(1, &(format[t.index++]), 1);
			t.count++;
		}
		t.count = t.count + ret;
	}
	va_end(ap);
	va_end(ap2);
	return (t.count);
}
