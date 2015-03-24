/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 03:10:47 by averkenn          #+#    #+#             */
/*   Updated: 2014/11/11 06:14:31 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *s1, const char *s2)
{
	int nb;
	int number;

	number = 0;
	nb = ft_strlen(s1);
	while (s2[number] != '\0')
	{
		s1[nb] = s2[number];
		nb++;
		number++;
	}
	s1[nb] = '\0';
	return (s1);
}
