#include "fdf.h"
#include <stdio.h>

int		**str_to_int(char *str)
{
	int i;
	int j;
	int k;
	int **tab = NULL;

	i = 0;
	j = 0;
	k = 0;
	tab = (int **)malloc(sizeof(int *) * size_y(str));
	while (str[i])
	{
		tab[j] = (int *)malloc(sizeof(int) * size_x(str, j));
		while(str[i] != '\n' && str[i])
		{
			tab[j][k++] = ft_atoi(str+i);
			while(ft_isdigit(str[i]) || str[i] == '-')
				i++;
			while(str[i] == ' ')
				i++;
		}
		k = 0;
		i++;
		j++;
	}
	return (tab);
}
