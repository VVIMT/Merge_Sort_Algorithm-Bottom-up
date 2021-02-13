/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_specs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:59:55 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/20 00:00:01 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_param(const char *format, va_list *ap2, t_types *t)
{
	int		sig;
	int		i;
	int		n;

	sig = 0;
	n = 0;
	while (format[t->index + n] && format[t->index + n] >= '0'
			&& format[t->index + n] <= '9')
	{
		n++;
		sig = 2;
	}
	i = t->index;
	if (sig == 2 && format[t->index + n] == '$')
	{
		t->index++;
		sig = 1;
		t->syntax = 1;
	}
	if (sig == 1)
		t->index = t->index + n;
	i = ft_atoi(format + i);
	while (--i > 0)
		va_arg(*ap2, void *);
	return (sig);
}

void	get_flag(const char *format, t_types *t)
{
	int	n;

	n = 0;
	while (format[t->index + n] &&
			(format[t->index + n] == '+' || format[t->index + n] == '-'
			|| format[t->index + n] == '0' || format[t->index + n] == '#'
			|| format[t->index + n] == ' '))
	{
		if (format[t->index + n] == '+')
			t->sig1++;
		if (format[t->index + n] == '-')
			t->sig2++;
		if (format[t->index + n] == '0')
			t->sig3++;
		if (format[t->index + n] == '#')
			t->sig4++;
		if (format[t->index + n] == ' ')
			t->sig5++;
		n++;
	}
	if (n > 0)
	{
		t->index = t->index + n;
		t->syntax = 2;
	}
}

size_t	get_width(const char *format, t_types *t)
{
	size_t	width;
	int		n;

	width = 0;
	n = 0;
	while (format[t->index + n]
			&& format[t->index + n] >= '0' && format[t->index + n] <= '9')
		n++;
	if (format[t->index + n] != '$')
		t->syntax = 3;
	if (t->syntax == 3 && n > 0)
		width = ft_atoi(format + t->index);
	t->index = t->index + n;
	return (width);
}

int		get_precision(const char *format, t_types *t, long precision)
{
	int	n;

	n = 0;
	if (format[t->index + n] && format[t->index + n] == '.')
	{
		precision = 0;
		n++;
		while (format[t->index + n]
				&& format[t->index + n] >= '0' && format[t->index + n] <= '9')
			n++;
	}
	if (n > 0)
	{
		t->syntax = 4;
		precision = ft_atoi(format + t->index + 1);
	}
	t->index = t->index + n;
	return (precision);
}

size_t	get_length(const char *format, t_types *t)
{
	int	sig;

	sig = 0;
	if (format[t->index] == 'h' && format[t->index + 1] != 'h')
		sig = 1;
	else if (format[t->index] == 'h' && format[t->index + 1] == 'h')
		sig = 11;
	else if (format[t->index] == 'l' && format[t->index + 1] != 'l')
		sig = 2;
	else if (format[t->index] == 'l' && format[t->index + 1] == 'l')
		sig = 12;
	else if (format[t->index] == 'j')
		sig = 3;
	else if (format[t->index] == 'z')
		sig = 4;
	if (sig > 0)
	{
		t->syntax = 5;
		if (sig > 0 && sig < 10)
			t->index++;
		else if (sig > 10)
			t->index = t->index + 2;
	}
	return (sig);
}
