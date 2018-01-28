/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:24:39 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 12:24:40 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <libft.h>
#include <point.h>
#include <mlx.h>
#include <math.h>
#include <mlxconn.h>
#include <ft_printf.h>
#include <image.h>
#include "../fdf.h"

void	put_point(int x, int y, int color, void *image)
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

void	draw_line_high(int *xy0, int *xy1, void *image)
{
	t_math_vars vars;

	vars.dx = xy1[0] - xy0[0];
	vars.dy = xy1[1] - xy0[1];
	vars.ii = 1;
	if (vars.dx < 0)
	{
		vars.ii = -1;
		vars.dx = -vars.dx;
	}
	vars.err = 2 * vars.dx - vars.dy;
	vars.y = xy0[1];
	vars.i = xy0[0];
	while (vars.y < xy1[1])
	{
		put_point(vars.i, vars.y, 0xffffff, image);
		if (vars.err > 0)
		{
			vars.i += vars.ii;
			vars.err -= 2 * vars.dy;
		}
		vars.err = vars.err + 2 * vars.dx;
		vars.y++;
	}
}

void	draw_line_low(int *xy0, int *xy1, void *image)
{
	t_math_vars	vars;

	vars.dx = xy1[0] - xy0[0];
	vars.dy = xy1[1] - xy0[1];
	vars.ii = 1;
	vars.err;
	if (vars.dy < 0)
	{
		vars.ii = -1;
		vars.dy = -vars.dy;
	}
	vars.err = 2 * vars.dy - vars.dx;
	vars.y = xy0[1];
	vars.i = xy0[0];
	while (vars.i < xy1[0])
	{
		put_point(vars.i, vars.y, 0xffffff, image);
		if (vars.err > 0)
		{
			vars.y += vars.ii;
			vars.err -= 2 * vars.dx;
		}
		vars.err = vars.err + 2 * vars.dy;
		vars.i++;
	}
}

void	draw_line(t_scene_state *state, void *v2, void *v1, void *image)
{
	int *xy0;
	int *xy1;

	xy0 = apply_state(v1, state);
	xy1 = apply_state(v2, state);
	if (abs(xy1[1] - xy0[1]) < abs(xy1[0] - xy0[0]))
	{
		if (xy0[0] > xy1[0])
			draw_line_low(xy1, xy0, image);
		else
			draw_line_low(xy0, xy1, image);
	}
	else
	{
		if (xy0[1] > xy1[1])
			draw_line_high(xy1, xy0, image);
		else
			draw_line_high(xy0, xy1, image);
	}
	free(xy0);
	free(xy1);
}

void	draw_poligons(void *s_map, void *image, t_scene_state *state)
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
			draw_line(state, map[i][j + 1], map[i][j++], image);
		j = 0;
		i++;
	}
	i = 0;
	while (map[i][j])
	{
		while (map[i + 1])
			draw_line(state, map[i + 1][j], map[i++][j], image);
		i = 0;
		j++;
	}
}
