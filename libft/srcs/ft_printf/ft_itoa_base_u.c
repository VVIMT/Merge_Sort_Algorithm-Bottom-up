/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 20:37:25 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/29 21:24:55 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_u(uintmax_t value, int base, int upper_case)
{
	uintmax_t	nb;
	uintmax_t	lvalue;
	char		*str;
	t_types		t;

	lvalue = value;
	nb = lvalue;
	t.n = 0;
	while (nb > 0)
	{
		nb = nb / base;
		t.n++;
	}
	nb = t.n;
	if (!(str = (char*)malloc(sizeof(char) * (nb + 2))))
		return (NULL);
	ft_bzero(str, nb + 2);
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	t.upper_case = upper_case;
	fill_tab(str, &t, lvalue, base);
	return (str);
}

void	fill_tab(char *str, t_types *t, uintmax_t lvalue, int base)
{
	t->n--;
	while (t->n >= 0 && lvalue > 0)
	{
		if (lvalue % base <= 9)
			str[t->n] = lvalue % base + '0';
		else if (lvalue % base > 9 && t->upper_case == 0)
			str[t->n] = lvalue % base - 10 + 'a';
		else if (lvalue % base > 9 && t->upper_case == 1)
			str[t->n] = lvalue % base - 10 + 'A';
		lvalue = lvalue / base;
		t->n--;
	}
}
