/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:20:44 by vinvimo           #+#    #+#             */
/*   Updated: 2016/11/07 19:20:46 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s && f)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		ft_strcpy(str, s);
		while (str[i])
		{
			str[i] = (*f)(str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
