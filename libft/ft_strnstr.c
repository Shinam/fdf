/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 04:36:02 by averkenn          #+#    #+#             */
/*   Updated: 2015/02/08 06:38:08 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t s;

	i = 0;
	s = 0;
	if (!s2)
		return ((char *)s1);
	while ((s1[i]) && (i < n))
	{
		while ((s1[i + s] == s2[s]) && ((i + s) < n) && (s1[i + s]))
			s++;
		if (s == ft_strlen(s2))
			return (&((char *)s1)[i]);
		else
			s = 0;
		i++;
	}
	return (NULL);
}
