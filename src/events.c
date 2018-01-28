/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:53:25 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/27 12:53:26 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <mlxconn.h>
#include <mlx.h>
#include <point.h>
#include <ft_printf.h>
#include "../fdf.h"

void	apply_else_events(int keycode, t_scene_state *scene_state, void *map)
{
	if (keycode == 91)
		scene_state->rot_x += 0.1;
	if (keycode == 69)
		scene_state->scale += 1;
	if (keycode == 78)
		scene_state->scale -= 1;
	if (keycode == 82)
	{
		get_rows_cols(map, scene_state);
		scene_state->rot_x = 0;
		scene_state->rot_y = 0;
		scene_state->rot_z = 0;
		scene_state->scale = 1;
	}
}

void	apply_events(int keycode, t_scene_state *scene_state, void *map)
{
	if (keycode == 0)
	{
		scene_state->scale = 1;
		get_rows_cols(map, scene_state);
	}
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		scene_state->x -= 2;
	if (keycode == 124)
		scene_state->x += 2;
	if (keycode == 125)
		scene_state->y += 2;
	if (keycode == 126)
		scene_state->y -= 2;
	if (keycode == 86)
		scene_state->rot_y -= 0.1;
	if (keycode == 88)
		scene_state->rot_y += 0.1;
	if (keycode == 84)
		scene_state->rot_x -= 0.1;
	apply_else_events(keycode, scene_state, map);
}

void	apply_hooks(void **s_mlx, void **map)
{
	t_mlx_class		*mlx;
	unsigned long	*param;

	param = malloc(sizeof(unsigned long*) * 2);
	mlx = *s_mlx;
	param[0] = (unsigned long)map;
	param[1] = *(unsigned long*)s_mlx;
	apply_transormation(0, param);
	mlx_key_hook(mlx->winx, apply_transormation, param);
}

int		apply_transormation(int keycode, void *param)
{
	static t_scene_state	scene_state;
	void					*map;
	t_mlx_class				*mlx;

	mlx = *((t_mlx_class **)param + 1);
	scene_state.offset = 50;
	scene_state.width = mlx->x;
	scene_state.height = mlx->y;
	map = *(int ***)param;
	apply_events(keycode, &scene_state, map);
	loop(&scene_state, map);
	return (1);
}
