#include <wchar.h>
#include <libft.h>
#include <Point.h>
#include <mlx.h>
#include <math.h>
#include <MLXConn.h>
#include <ft_printf.h>
#include <Image.h>
#include "../fdf.h"

void put_point(int x, int y, int color, void *image)
{
	t_mlx_class *mlx;
	int			*img_data;
	t_image		*img;

	img = ((t_image*)image);
	x += img->width / 2;
	y += img->height / 2;
	if (x > img->width - 1 || y > img->height - 1)
		return ;
	if (x < 0 || y < 0)
		return ;
	img_data = ((t_image*)image)->image_data;
	img_data[x + (y * img->width)] = color;
}

void put_image(void *s_image, int x, int y)
{
	t_image		*img;
	t_mlx_class	*mlx;

	img = (t_image*)s_image;
	mlx = get_mlx(NULL);
	mlx_put_image_to_window(mlx->conn, mlx->winx, img->image_ptr, x, y);
}

void draw_line_high(int x0, int y0, int x1, int y1, void *image)
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
		put_point(i, y, 0xffffff, image);
		if (err > 0)
		{
			i += xi;
			err -= 2*dy;
		}
		err = err + 2*dx;
		y++;
	}
}

void draw_line_low(int x0, int y0, int x1, int y1, void *image)
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
		put_point(i, y, 0xffffff, image);
		if (err > 0)
		{
			y += yi;
			err -= 2*dx;
		}
		err = err + 2*dy;
		i++;
	}
}

void draw_line(t_scene_state *state, void *v2, void *v1, void *image)
{
	int *xy0;
	int *xy1;

	xy0 = apply_state(v1, state);
	xy1 = apply_state(v2,state);
	if (abs(xy1[1] - xy0[1]) < abs(xy1[0] - xy0[0]))
    {
        if (xy0[0] > xy1[0])
			draw_line_low(xy1[0], xy1[1], xy0[0], xy0[1], image);
        else
			draw_line_low(xy0[0], xy0[1], xy1[0], xy1[1], image);
    }
	else
    {
        if (xy0[1] > xy1[1])
			draw_line_high(xy1[0], xy1[1], xy0[0], xy0[1], image);
        else
			draw_line_high(xy0[0], xy0[1], xy1[0], xy1[1], image);
    }
	free(xy0);
	free(xy1);
}

void draw_poligons(void *s_map, void *image, t_scene_state *state)
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
			draw_line(state, map[i][j + 1], map[i][j], image);
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
			draw_line(state, map[i + 1][j], map[i][j], image);
			i++;
		}
		i = 0;
		j++;
	}
}
