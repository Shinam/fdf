/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 05:26:31 by averkenn          #+#    #+#             */
/*   Updated: 2015/02/15 03:56:00 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	size_t	j;

	j = 0;
	if ((i = n) == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (i && ++j)
		i = i / 10;
	if (n < 0)
		j++;
	str = ft_strnew(j-- + 1);
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n)
	{
		str[j--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
