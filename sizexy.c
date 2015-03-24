#include "fdf.h"
#include <stdio.h>

int		size_x(char *str, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (n > 0)
	{
		while (str[i] != '\n')
			i++;
		i++;
		n--;
	}
	while (str[i] && n == 0)
	{
		while(ft_isdigit(str[i]) || str[i] == '-')
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == '\n')
			n--;
		j++;
	}
	return (j);
}

int		size_y(char *str)
{
	int	nb;
	int	i;

	nb = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

char	*str_donnee(int fd)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	str = ft_strnew(1);
	while (get_next_line(fd, &tmp))
	{
		i = ft_strlen(tmp);
		tmp[i] = '\n';
		str = ft_strjoin(str, tmp);
	}
	i = ft_strlen(str) - 1;
	str[i] = '\0';
	return (str);
}

/*int		main(void)
{
	int	fd;
	int	nb;
	int	nm;
	char *str;

	fd = open("test_maps/42.fdf", O_RDONLY);
	if (fd == -1)
		write(1, "open error", 10);
	str = str_donnee(fd);
	nb = size_y(str);
	nm = size_x(str, 1);
	str_to_int(str);
	return (0);
}*/
