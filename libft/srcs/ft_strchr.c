/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:18:00 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:18:01 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*x;

	i = 0;
	x = (char *)s;
	while (x[i] != c && x[i])
		i++;
	if (s[i] == c)
		return (x + i);
	return (NULL);
}
