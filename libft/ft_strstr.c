/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 03:57:19 by averkenn          #+#    #+#             */
/*   Updated: 2015/02/09 02:00:01 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	size_t c;
	size_t d;

	c = 0;
	d = 0;
	if (!s1)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	if ((ft_strlen(s1) == 0) && (ft_strlen(s2) == 0))
		return ("");
	while (s1[c])
	{
		while ((s1[c + d] == s2[d]) && (s1[c + d]))
			d++;
		if (d == ft_strlen(s2))
			return (&((char *)s1)[c]);
		c++;
	}
	return (NULL);
}
