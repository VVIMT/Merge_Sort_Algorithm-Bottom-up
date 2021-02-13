/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:15:45 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/23 23:42:40 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_char(char const *s1, char const *s2, char c)
{
	char	*dst;
	size_t	x;
	size_t	y;

	y = 0;
	if (!s1 || !s2)
		return (NULL);
	x = ft_strlen(s1);
	while (s2[y] && s2[y] != '\n')
		y++;
	if (!(dst = (char *)malloc(sizeof(char) * (x + y + 1))))
		return (NULL);
	ft_strcpy(dst, s1);
	x = 0;
	y = 0;
	while (dst[x])
		x++;
	while (s2[y] && s2[y] != c)
	{
		dst[x + y] = s2[y];
		y++;
	}
	dst[x + y] = '\0';
	return (dst);
}
