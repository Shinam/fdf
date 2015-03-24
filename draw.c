#include "fdf.h"
#include <stdio.h>

typedef	struct		s_env
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	int		fd;
	char	*str;
	float	num;
	float	nb;
}					t_env;

typedef	struct		s_coord
{
	float		x;
	float		y;
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	int			col;
}					t_coord;

void		d_line_x(int **tab, int x, int y, t_env *e)
{
	t_coord	c;

	while (y < size_y(e->str))
	{
		x = 0;
		while (x < size_x(e->str, y) - 1)
		{
			c.x1 = 300 + (e->num * x - e->nb * y);
			c.y1 = ((((e->num / 2)* x) + ((e->nb / 2) * y)) - (tab[y][x]));
			c.x2 = 300 + (e->num * (x + 1) - e->nb * y);
			c.y2 = ((((e->num / 2) * (x + 1)) + ((e->nb / 2) * y)) - (tab[y][x + 1]));
			c.x = c.x1;
			while (c.x <= c.x2)
			{
				c.col = 0xFF0000 + (tab[y][x] / 0x00FF);
				if (tab[y][x] < 0)
					c.col = 0x0000FF;
				mlx_pixel_put(e->mlx, e->win, c.x, c.y1 + ((c.y2 - c.y1) * (c.x - c.x1)) / (c.x2 - c.x1), c.col);
				c.x++;
			}
			x++;
		}
		y++;
	}
}
void		d_line_y(int	**tab, int x, int y, t_env *e)
{
	t_coord c;

	c.col = 0x00FF00;
	while (y < size_y(e->str) - 1)
	{
		x = 0;
		while (x < size_x(e->str, y))
		{
			c.x1 = 300 + (e->num * x - e->nb * y);
			c.y1 = ((((e->num / 2) * x) + ((e->nb / 2) * y)) - (tab[y][x]));
			c.x2 = 300 + (e->num * x - e->nb * (y + 1));
			c.y2 = ((((e->num / 2) * x) + ((e->nb / 2) * (y + 1))) - (tab[y + 1][x]));
			c.y = c.y1;
			while (c.y <= c.y2)
			{
				c.col = 0xFF0000 + (tab[y][x] / 0x00FF);
				if (tab[y][x] < 0)
					c.col = 0x0000FF;
				mlx_pixel_put(e->mlx, e->win, c.x1 + ((c.x2 - c.x1) * (c.y - c.y1)) / (c.y2 - c.y1), c.y, c.col);
				c.y++;
			}
			x++;
		}
		y++;
	}
}

void		d_line_y2(int	**tab, int x, int y, t_env *e)
{
	t_coord c;

	c.col = 0x00FF00;
	while (y < size_y(e->str) - 1)
	{
		x = 0;
		while (x < size_x(e->str, y))
		{
			c.x1 = 300 + (e->num * x - e->nb * y);
			c.y1 = ((((e->num / 2) * x) + ((e->nb / 2) * y)) - (tab[y][x]));
			c.x2 = 300 + (e->num * x - e->nb * (y + 1));
			c.y2 = ((((e->num / 2) * x) + ((e->nb / 2) * (y + 1))) - (tab[y + 1][x]));
			c.y = c.y2;
			while (c.y <= c.y1)
			{
				c.col = 0xFF0000 + (tab[y][x] / 0x00FF);
				if (tab[y][x] < 0)
					c.col = 0x0000FF;
				mlx_pixel_put(e->mlx, e->win, c.x2 + ((c.x1 - c.x2) * (c.y - c.y2)) / (c.y1 - c.y2), c.y, c.col);
				c.y++;
			}
			x++;
		}
		y++;
	}
}


void		draw(t_env *e)
{
	int		x;
	int		y;
	int		**tab = NULL;

	x = 0;
	y = 0;
	e->str = str_donnee(e->fd);
	tab = str_to_int(e->str);
	while (y < size_y(e->str))
	{
		x = 0;
		while (x < size_x(e->str, y))
		{
			printf("%3d", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	x = 0;
	y = 0;
	d_line_x(tab, x, y, e);
	d_line_y(tab, x, y, e);
	d_line_y2(tab, x, y, e);
	//mlx_pixel_put(e->mlx, e->win, 150+(20 * x - 15 * y), 150+(((20 / 2) * x) + ((15 / 2) * y) - tab[y][x]), 0xFF0000);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return(0);
}

int		main(void)
{
	t_env e;

	e.fd = -1;
	e.num = 4;
	e.nb = 4;
	e.fd = open("test_maps/NOAA_ETOPO_AUSTRALIA.OCEAN0.S.fdf", O_RDONLY);
	if (e.fd == -1)
	{
		write(1, "open error", 10);
		return (1);
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1600, 800, "fdf");
	e.img_ptr = mlx_new_image(e.mlx, 1600, 800);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
