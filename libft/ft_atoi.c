/* ************************************************************************** */
/*                                                                            */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <averkenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 13:58:41 by averkenn          #+#    #+#             */
/*   Updated: 2014/11/22 17:42:01 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	plus;

	i = 0;
	s = 0;
	plus = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+' && plus == 0)
			plus++;
		else if (str[i] == '-' && plus == 0)
			plus--;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		s = s * 10 + (str[i] - 48);
		i++;
	}
	if (plus < 0)
		return (s * -1);
	return (s);
}
