/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:08:32 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:08:35 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
	{
		return (1);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	int		a;
	int		sign;

	i = 0;
	a = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '+' || str[i] == '-') ? i + 1 : i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = 10 * a + (str[i] - '0');
		i++;
	}
	a *= sign;
	return (a);
}
