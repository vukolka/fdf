#include <Point.h>
#include <String.h>
#include <classes_lib.h>
#include <MLXConn.h>
#include <mlx.h>
#include <fcntl.h>
#include <get_next_line.h>
#include "ft_printf.h"
#include "new.h"
#include "../fdf.h"
#include <math.h>

int		render_screen(unsigned int keycode, void *param)
{
	t_mlx_class	*mlx;
	void		**map;

	ft_printf("keycode :%d\n", keycode);
	map = *(void **)param;
	mlx = *(((t_mlx_class**)param) + 1);
	mlx_clear_window(mlx->conn, mlx->winx);
	if (keycode == RIGHT)
		move_right(map);
	if (keycode == LEFT)
		move_left(map);
	draw_poligons(mlx, map);
	return (1);
}

void	modify_vector(void *s_vector, int x, int y, int z)
{
	t_point *vector;

	vector = s_vector;
	vector->x += x;
	vector->y += y;
	vector->z += z;
}

int     main(int argc, char **argv)
{
	t_list	*map;
	void	*mlx;
	void	**arr_map;

	map = NULL;
	make_classes();
	mlx = new(g_mlx_class, 1000, 1000, "This is how you get fucked");
	arr_map = parce_map(&map, argv[1]);
	apply_hooks(&mlx, arr_map);
	loop(NULL, arr_map, NULL);
	mlx_loop(((t_mlx_class*)mlx)->conn);
	return (0);
}