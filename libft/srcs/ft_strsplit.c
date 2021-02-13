/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:22:38 by vinvimo           #+#    #+#             */
/*   Updated: 2016/12/07 22:32:45 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_size(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	int	ft_word(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			i--;
			j++;
		}
		i++;
	}
	return (j);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**d;
	size_t	i;
	size_t	index;

	if (!s)
		return (NULL);
	if (!(d = (char**)malloc(sizeof(*d) * (ft_word(s, c) + 1))))
		return (NULL);
	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(d[index] = ft_strsub(s, i, ft_size((s + i), c))))
				return (NULL);
			index++;
			i = i + ft_size((s + i), c);
		}
		else
			i++;
	}
	d[index] = NULL;
	return (d);
}
