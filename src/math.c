/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:55:56 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/27 12:55:57 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <point.h>
#include <stdlib.h>
#include <math.h>
#include <ft_printf.h>
#include <new.h>
#include <image.h>
#include <mlxconn.h>
#include "../fdf.h"

void	get_rows_cols(void *s_map, t_scene_state *state)
{
	int		i;
	t_point	***map;

	map = (t_point***)s_map;
	i = 0;
	while (map[0][i])
		i++;
	state->y = -i / 2;
	i = 0;
	while (map[i])
		i++;
	state->x = -i / 2;
}

int		*apply_rotation(void *s_vector, double rx, double ry, double rz)
{
	t_point	*vector;
	int		x;
	int		y;
	int		z;
	int		*res;

	res = malloc(8);
	vector = s_vector;
	x = vector->x;
	y = vector->y;
	z = vector->z;
	y = (int)(y * cos(rx) + z * sin(rx));
	z = (int)(z * cos(rx) - y * sin(rx));
	x = (int)(x * cos(ry) - z * sin(ry));
	x = (int)(x * cos(rz) + y * sin(rz));
	y = (int)(y * cos(rz) - x * sin(rz));
	res[0] = x;
	res[1] = y;
	return (res);
}

int		*apply_state(void *s_vector, t_scene_state *state)
{
	t_point vector;
	t_point *self;

	self = (t_point *)s_vector;
	vector.x = self->x + state->x;
	vector.y = self->y + state->y;
	vector.z = self->z;
	vector.x *= state->scale;
	vector.y *= state->scale;
	vector.z *= state->scale / 4;
	return (apply_rotation(&vector, state->rot_x, state->rot_y, 0));
}

void	put_image(void *s_image, int x, int y)
{
	t_image		*img;
	t_mlx_class	*mlx;

	img = (t_image*)s_image;
	mlx = get_mlx(NULL);
	mlx_put_image_to_window(mlx->conn, mlx->winx, img->image_ptr, x, y);
}
