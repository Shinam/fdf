/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:26:23 by averkenn          #+#    #+#             */
/*   Updated: 2015/02/15 04:02:54 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strdiv(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		k++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc((ft_strdiv(s, c) + 1) * sizeof(char *));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		k = 0;
		while (s[i + k] != c && s[i + k])
			k++;
		tab[j] = ft_strnew(k + 1);
		ft_strncpy(tab[j], &s[i], k);
		tab[j][k] = 0;
		i += ft_strlen(tab[j]);
		j = (k) ? j + 1 : j;
	}
	tab[j] = NULL;
	return (tab);
}
