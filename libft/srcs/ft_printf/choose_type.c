/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 20:39:53 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/29 20:39:57 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		var_1(char c, va_list *ap, t_types *t, int *ret)
{
	if (c == 's' && t->length == 0)
		*ret = get_s(t, va_arg(*ap, char *), 0);
	else if (c == 'S' || (c == 's' && t->length == 2))
		*ret = get_upper_s(t, va_arg(*ap, wchar_t *));
	else if ((c == 'd' || c == 'i') && t->length == 0)
		*ret = get_d(t, va_arg(*ap, int));
	else if ((c == 'd' || c == 'i') && t->length == 3)
		*ret = get_d(t, va_arg(*ap, intmax_t));
	else if ((c == 'd' || c == 'i') && t->length == 4)
		*ret = get_d(t, va_arg(*ap, size_t));
	else if ((c == 'd' || c == 'i') && t->length == 1)
		*ret = get_d(t, (short)va_arg(*ap, intmax_t));
	else if ((c == 'd' || c == 'i') && t->length == 11)
		*ret = get_d(t, (char)va_arg(*ap, intmax_t));
	else if (c == 'D' || ((c == 'd' || c == 'D' || c == 'i') && t->length == 2))
		*ret = get_d(t, va_arg(*ap, long));
	else if ((c == 'd' || c == 'i') && t->length == 12)
		*ret = get_d(t, va_arg(*ap, long long));
	return (*ret);
}

int		var_2(char c, va_list *ap, t_types *t, int *ret)
{
	if (c == 'u' && t->length == 0)
		*ret = get_u(t, va_arg(*ap, unsigned int));
	else if (c == 'u' && t->length == 3)
		*ret = get_u(t, va_arg(*ap, uintmax_t));
	else if (c == 'u' && t->length == 4)
		*ret = get_u(t, va_arg(*ap, size_t));
	else if (c == 'u' && t->length == 1)
		*ret = get_u(t, (unsigned short)va_arg(*ap, uintmax_t));
	else if (c == 'u' && t->length == 11)
		*ret = get_u(t, (unsigned char)va_arg(*ap, uintmax_t));
	else if (c == 'U' || ((c == 'u' || c == 'U') && t->length == 2))
		*ret = get_u(t, va_arg(*ap, unsigned long));
	else if (c == 'u' && t->length == 12)
		*ret = get_u(t, va_arg(*ap, unsigned long long));
	else if (c == 'o' && t->length == 0)
		*ret = get_o(t, va_arg(*ap, unsigned int));
	else if (c == 'o' && t->length == 3)
		*ret = get_o(t, va_arg(*ap, uintmax_t));
	else if (c == 'o' && t->length == 4)
		*ret = get_o(t, va_arg(*ap, size_t));
	return (*ret);
}

int		var_3(char c, va_list *ap, t_types *t, int *ret)
{
	if (c == 'o' && t->length == 1)
		*ret = get_o(t, (unsigned short)va_arg(*ap, uintmax_t));
	else if (c == 'o' && t->length == 11)
		*ret = get_o(t, (unsigned char)va_arg(*ap, uintmax_t));
	else if (c == 'O' || ((c == 'o' || c == 'O') && t->length == 2))
		*ret = get_o(t, va_arg(*ap, unsigned long));
	else if (c == 'o' && t->length == 12)
		*ret = get_o(t, va_arg(*ap, unsigned long long));
	else if (c == 'x' && t->length == 0)
		*ret = get_x(t, va_arg(*ap, unsigned int), 0);
	else if (c == 'x' && t->length == 3)
		*ret = get_x(t, va_arg(*ap, uintmax_t), 0);
	else if (c == 'x' && t->length == 4)
		*ret = get_x(t, va_arg(*ap, size_t), 0);
	else if (c == 'x' && t->length == 1)
		*ret = get_x(t, (unsigned short)va_arg(*ap, uintmax_t), 0);
	else if (c == 'x' && t->length == 11)
		*ret = get_x(t, (unsigned char)va_arg(*ap, uintmax_t), 0);
	else if (c == 'x' && t->length == 2)
		*ret = get_x(t, va_arg(*ap, unsigned long), 0);
	else if (c == 'x' && t->length == 12)
		*ret = get_x(t, va_arg(*ap, unsigned long long), 0);
	return (*ret);
}
