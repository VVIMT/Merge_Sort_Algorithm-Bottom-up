/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:19:55 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:19:56 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	x;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	x = ft_strlen(s1);
	y = ft_strlen(s2);
	if (!(dst = (char *)malloc(sizeof(char) * (x + y + 1))))
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	return (dst);
}
