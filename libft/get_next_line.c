/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averkenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 18:00:46 by averkenn          #+#    #+#             */
/*   Updated: 2015/02/17 07:45:08 by averkenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cpy_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strnew(ft_strlen(str));
	while (str[i] && (str[i] != '\n'))
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = ft_strnew(ft_strlen(str));
	while (str[i] != '\n' && str[i])
		i++;
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	return (temp);
}

int		get_next_line(int const fd, char **line)
{
	static char	*temp[MAX_FILE];
	char		*buffer;
	int			ret;

	if (fd < 0 || !line || !(buffer = ft_strnew(BUF_SIZE + 1)))
		return (-1);
	while (!(ft_strchr(temp[fd], '\n')) && (ret = read(fd, buffer, BUF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buffer);
	}
	*line = ft_cpy_line(temp[fd]);
	temp[fd] = ft_next(temp[fd]);
	if (ret)
		return (1);
	return (0);
}
