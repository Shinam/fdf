/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 00:08:54 by averkenn          #+#    #+#             */
/*   Updated: 2014/11/11 07:01:17 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcpy(char *dst, const char *src)
{
	size_t nb;

	nb = 0;
	while (src[nb] != '\0')
	{
		dst[nb] = src[nb];
		nb++;
	}
	while (dst[nb] != '\0')
	{
		dst[nb] = '\0';
		nb++;
	}
	return (dst);
}
