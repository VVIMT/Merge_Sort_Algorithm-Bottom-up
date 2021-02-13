/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:22:25 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:22:26 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*x;

	x = (char *)s;
	i = 0;
	while (x[i])
		i++;
	while (i > 0 && x[i] != c)
		i--;
	if (x[i] == c)
		return (x + i);
	return (NULL);
}
