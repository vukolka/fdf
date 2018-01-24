//
// Created by vukolov on 12.01.18.
//

#include <stdlib.h>
#include <libft.h>
#include <MLXConn.h>
#include <mlx.h>
#include <Point.h>
#include <ft_printf.h>
#include "../fdf.h"

void	close_win()
{
	exit (0);
}

void apply_events(int keycode, t_scene_state *scene_state)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65361)
		scene_state->x -= 2;
	if (keycode == 65363)
		scene_state->x += 2;
	if (keycode == 65364)
		scene_state->y += 2;
	if (keycode == 65362)
		scene_state->y -= 2;
	if (keycode == 65431)
		scene_state->rot_y -= 0.1;
	if (keycode == 65433)
		scene_state->rot_y += 0.1;
	if (keycode == 65430)
		scene_state->rot_x -= 0.1;
	if (keycode == 65432)
		scene_state->rot_x += 0.1;
	if (keycode == 65451)
		scene_state->scale += 1;
	if (keycode == 65453)
		scene_state->scale -= 1;
	if (keycode == 65438)
	{
		scene_state->x = 0;
		scene_state->y = 0;
		scene_state->rot_x = 0;
		scene_state->rot_y = 0;
		scene_state->rot_z = 0;
		scene_state->scale = 1;
	}
}

void	apply_hooks(void **s_mlx, void **map)
{
	t_mlx_class 	*mlx;
	unsigned long	*param;

	param = malloc(sizeof(unsigned long*) * 2);
	mlx = *s_mlx;
	param[0] = (unsigned long)map;
	param[1] = *(unsigned long*)s_mlx;
	mlx_key_hook(mlx->winx, apply_transormation, param);
}

int		apply_transormation(int keycode, void *param)
{
	static t_scene_state	scene_state;
	void *map;

	scene_state.offset = 50;
	scene_state.width = 1000;
	scene_state.height = 1000;
	map = *(int ***)param;
	apply_events(keycode, &scene_state);
	loop(&scene_state, map);
	return (1);
}
