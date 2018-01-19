#include <Point.h>
#include <String.h>
#include <classes_lib.h>
#include <MLXConn.h>
#include <fcntl.h>
#include <get_next_line.h>
#include "ft_printf.h"
#include "new.h"
#include "../fdf.h"
#include "../mlx.h"
#include <math.h>



int		render_screen(unsigned int keycode, void *param)
{
	t_mlx_class	*mlx;
	void		**map;

	map = *(void **)param;
	mlx = *(((t_mlx_class**)param) + 1);
	mlx_clear_window(mlx->conn, mlx->winx);
	if (keycode == 126)
		move_right(map);
	if (keycode == 125)
		move_left(map);
	draw_poligons(mlx, map);
	return (1);
}

void	modify_vector(void *s_vector, int x, int y, int z)
{
	t_point *vector;

	vector = ((t_list*)s_vector)->content;
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
	mlx = new(g_mlx_class, 1500, 1500, "This is how you get fucked");
	arr_map = parce_map(&map, argv[1]);
	apply_hooks(&mlx, arr_map);
	mlx_loop(((t_mlx_class*)mlx)->conn);
	return (0);
}