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
#include <Image.h>

int     main(int argc, char **argv)
{
	t_list	*map;
	void	*mlx;
	void	**arr_map;

	make_classes();

	mlx = new(g_mlx_class, 1000, 1000, "This is how you get fucked");
	get_mlx(mlx);
	map = NULL;
	arr_map = parce_map(&map, argv[1]);

	apply_hooks(&mlx, arr_map);

	loop(NULL, arr_map);

	mlx_loop(((t_mlx_class*)mlx)->conn);
	return (0);
}