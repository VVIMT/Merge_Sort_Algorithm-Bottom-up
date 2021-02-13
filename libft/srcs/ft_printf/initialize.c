/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:59:44 by vinvimo           #+#    #+#             */
/*   Updated: 2017/06/29 20:39:39 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize(t_types *t)
{
	t->pointer = 0;
	t->ret = 0;
	t->sig1 = 0;
	t->sig2 = 0;
	t->sig3 = 0;
	t->sig4 = 0;
	t->sig5 = 0;
	t->syntax = -1;
	t->param = 0;
	t->width = 0;
	t->precision = -1;
	t->length = 0;
	t->n = 0;
	t->x = 0;
	t->y = 0;
	t->c = 0;
	t->d = 0;
	t->u = 0;
	t->oct = 0;
	t->hex = 0;
	t->bin = 0;
	t->dst = NULL;
	t->str = NULL;
	t->tmp = NULL;
	t->upper_dst = NULL;
}
