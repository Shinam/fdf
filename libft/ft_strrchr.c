/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 00:15:08 by averkenn          #+#    #+#             */
/*   Updated: 2015/02/09 01:48:52 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	s = s + i;
	if (!s)
		return (NULL);
	while (i-- >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (0);
}
