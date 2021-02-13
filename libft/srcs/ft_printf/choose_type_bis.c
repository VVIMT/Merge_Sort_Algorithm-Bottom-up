/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 20:40:05 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/29 20:40:08 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		var_4(char c, va_list *ap, t_types *t, int *ret)
{
	if (c == 'X' && t->length == 0)
		*ret = get_x(t, va_arg(*ap, unsigned int), 1);
	else if (c == 'X' && t->length == 3)
		*ret = get_x(t, va_arg(*ap, uintmax_t), 1);
	else if (c == 'X' && t->length == 4)
		*ret = get_x(t, va_arg(*ap, size_t), 1);
	else if (c == 'X' && t->length == 1)
		*ret = get_x(t, (unsigned short)va_arg(*ap, uintmax_t), 1);
	else if (c == 'X' && t->length == 11)
		*ret = get_x(t, (unsigned char)va_arg(*ap, uintmax_t), 1);
	else if (c == 'X' && t->length == 2)
		*ret = get_x(t, va_arg(*ap, unsigned long), 1);
	else if (c == 'X' && t->length == 12)
		*ret = get_x(t, va_arg(*ap, unsigned long long), 1);
	else if ((c == 'c' || (c == '%' && t->syntax > -1)) && t->length == 0)
		*ret = get_c(t, (char)va_arg(*ap, int), 0);
	else if (c == 'C' || (c == 'c' && t->length == 2))
		*ret = get_c(t, (wchar_t)va_arg(*ap, wint_t), 0);
	return (*ret);
}

int		var_5(char c, va_list *ap, t_types *t, int *ret)
{
	if (c == 'b' && t->length == 0)
		*ret = get_b(t, va_arg(*ap, unsigned int));
	else if (c == 'b' && t->length == 3)
		*ret = get_b(t, va_arg(*ap, uintmax_t));
	else if (c == 'b' && t->length == 4)
		*ret = get_b(t, va_arg(*ap, size_t));
	else if (c == 'b' && t->length == 1)
		*ret = get_b(t, (unsigned short)va_arg(*ap, uintmax_t));
	else if (c == 'b' && t->length == 11)
		*ret = get_b(t, (unsigned char)va_arg(*ap, uintmax_t));
	else if (c == 'b' && t->length == 2)
		*ret = get_b(t, va_arg(*ap, unsigned long));
	else if (c == 'b' && t->length == 12)
		*ret = get_b(t, va_arg(*ap, unsigned long long));
	return (*ret);
}

int		var_6(char c, va_list *ap, t_types *t, int *ret)
{
	if (c == 'p')
	{
		t->pointer = 1;
		t->sig4++;
		t->hex = va_arg(*ap, uintmax_t);
		if (t->hex)
			*ret = get_x(t, t->hex, 0);
		else
			*ret = get_x(t, 0, 0);
	}
	else if (c)
		*ret = get_c(t, c, 0);
	return (*ret);
}
