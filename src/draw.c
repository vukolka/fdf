#include <wchar.h>
#include <libft.h>
#include <Point.h>
#include <mlx.h>
#include <math.h>
#include <MLXConn.h>
#include <ft_printf.h>
#include "../fdf.h"

void	put_point(void *s_mlx, int x, int y, int color)
{
	t_mlx_class *mlx;

	mlx = s_mlx;
	mlx_pixel_put(mlx->conn, mlx->winx, x, y, color);
}

draw_line_high(void *mlx, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	int err;
	int y;
	int i;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	err = 2 * dx - dy;
	y = y0;
	i = x0;
	while (y < y1)
	{
        put_point(mlx ,i, y, 0xffffff);
		if (err > 0)
		{
			i += xi;
			err -= 2*dy;
		}
		err = err + 2*dx;
		y++;
	}
}

draw_line_low(void *s_mlx, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	int err;
	int y;
	int i;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	err = 2 * dy - dx;
	y = y0;
	i = x0;
	while (i < x1)
	{
        put_point(s_mlx, i, y, 0xffffff);
		if (err > 0)
		{
			y += yi;
			err -= 2*dx;
		}
		err = err + 2*dy;
		i++;
	}
}

void 	draw_line(void *s_mlx, void *v1, void *v2)
{
	int *xy0;
	int *xy1;

	xy0 = apply_rotation(v1, -0.2, -0.3, -0.3);
	xy1 = apply_rotation(v2, -0.2, -0.3, -0.3);
    if (abs(xy1[1] - xy0[1]) < abs(xy1[0] - xy0[0]))
    {
        if (xy0[0] > xy1[0])
            draw_line_low(s_mlx, xy1[0], xy1[1], xy0[0], xy0[1]);
        else
            draw_line_low(s_mlx, xy0[0], xy0[1], xy1[0], xy1[1]);
    }
    else
    {
        if (xy0[1] > xy1[1])
            draw_line_high(s_mlx, xy1[0], xy1[1], xy0[0], xy0[1]);
        else
            draw_line_high(s_mlx, xy0[0], xy0[1], xy1[0], xy1[1]);
    }
}

void	draw_poligons(void *mlx, void *s_map)
{
	t_point			***map;
	int				i;
	int				j;

	map = (t_point ***)s_map;
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
	i = 0;
	j = 0;
	while (map[i][j])
	{
		while (map[i + 1])
		{
			draw_line(mlx, map[i][j], map[i + 1][j]);
			i++;
		}
		i = 0;
		j++;
	}
}
