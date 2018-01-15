//
// Created by vukolov on 12.01.18.
//

#include <stdlib.h>
#include <libft.h>
#include <MLXConn.h>
#include <mlx.h>
#include "../fdf.h"

void	move_right(void **map)
{
	for_each_lst((t_list*)map, modify_vector, 10, 10, 0);
}

void	move_left(void **map)
{

}

void	close_win()
{
	exit (0);
}

void	apply_hooks(void **s_mlx, void **map)
{
	t_mlx_class 	*mlx;
	unsigned long	*param;

	param = malloc(sizeof(unsigned long*) * 2);
	mlx = *s_mlx;
	param[0] = (unsigned long)map;
	param[1] = *(unsigned long*)s_mlx;
	mlx_key_hook(mlx->winx, render_screen, param);
}
