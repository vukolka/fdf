//
// Created by vukolov on 12.01.18.
//

#include <stdlib.h>
#include <libft.h>
#include <MLXConn.h>
#include <mlx.h>
#include <Point.h>
#include "../fdf.h"

void	close_win()
{
	exit (0);
}

void apply_events(int keycode, t_scene_state *scene_state)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		scene_state->x -= 2;
	if (keycode == 124)
		scene_state->x += 2;
	if (keycode == 125)
		scene_state->y -= 2;
	if (keycode == 126)
		scene_state->x += 2;
	if (keycode == 86)
		scene_state->rot_y -= 0.1;
	if (keycode == 88)
		scene_state->rot_y += 0.1;
	if (keycode == 84)
		scene_state->rot_x -= 0.1;
	if (keycode == 91)
		scene_state->rot_x += 0.1;
	if (keycode == 69)
		scene_state->scale += 1;
	if (keycode == 78)
		scene_state->scale -= 1;
	if (keycode == 82)
	{
		scene_state->x = 0;
		scene_state->y = 0;
		scene_state->rot_x = 0;
		scene_state->rot_y = 0;
		scene_state->rot_z = 0;
		scene_state->scale = 0;
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

int		apply_transormation(void **s_map, int keycode)
{
	static t_scene_state	scene_state;

	apply_events(keycode, &scene_state);
	loop(&scene_state, s_map, NULL);
	return (1);
}
