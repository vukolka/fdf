#include <wchar.h>
#include <libft.h>
#include <Point.h>
#include <mlx.h>
#include <MLXConn.h>
#include <ft_printf.h>
#include "../fdf.h"

void	put_point(void *s_vector, void *s_mlx)
{
	t_point *vector;
	t_mlx_class *mlx;
	int 	*res;

	mlx = s_mlx;
	vector = s_vector;
	res = apply_rotation(s_vector, 0.6, 0.5, 0);
	mlx_pixel_put(mlx->conn, mlx->winx, res[0], res[1], 255);
	free(res);
}

void 	draw_line(void *s_mlx, void *v1, void *v2)
{
	t_mlx_class *mlx = s_mlx;
	int		y;
	int		dx;
	int 	dy;
	double	c;
	int		x;
	double	k;

	int *p1 = apply_rotation(v1, 0.4, 0.4, 0);
	int *p2 = apply_rotation(v2, 0.4, 0.4, 0);
	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	c = 0;
	if (dx == 0)
		k = 0;
	else
		k = dy / dx;
	y = p1[1];
	x = p1[0];
	while (x != p2[0])
	{
		mlx_pixel_put(mlx->conn, mlx->winx, x, y, 255);
		c = c + k;
		if (abs(c) >= 0.5)
		{
			y = y + 1;
			c = c - 1;
		}
		if (x > p2[0])
			x--;
		else
			x++;
	}
}

void	draw_poligons(void *mlx, void *s_map)
{
	unsigned long	**map;
	int				i;
	int				j;

	map = (unsigned long **)s_map;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j + 1])
		{
			draw_line(mlx, map[i][j], map[i][j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}
