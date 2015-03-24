/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:15:27 by averkenn          #+#    #+#             */
/*   Updated: 2015/02/07 22:15:22 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		len;
	char	*str;

	start = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[start] && ft_isspace(s[start]))
		start++;
	while (ft_isspace(s[len]) && len > 0)
		len--;
	if (len == 0)
		return ("");
	len = len - start;
	str = ft_strsub(s, start, len + 1);
	if (!str)
		return ("");
	return (str);
}
