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
	void	*map;
	void	*mlx;

	make_classes();

	mlx = new(g_mlx_class, 1000, 1000, "fdf");
	get_mlx(mlx);

	map = parce_map(argv[1]);
	//TODO parcing should handle exceptions

	apply_hooks(&mlx, map);
	mlx_loop(((t_mlx_class*)mlx)->conn);
	return (0);
}