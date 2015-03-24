/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 07:39:56 by averkenn          #+#    #+#             */
/*   Updated: 2014/11/22 17:45:39 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	if (i == ft_strlen(s1))
		if (i == ft_strlen(s2))
			return (1);
	return (0);
}
