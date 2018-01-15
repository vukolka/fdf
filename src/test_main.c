#include <new.h>
#include <MLXConn.h>
#include <mlx.h>
#include <Point.h>
#include <classes_lib.h>
#include "../fdf.h"

int		main()
{
	void *mlx_ptr;

	make_classes();
	mlx_ptr = new(g_mlx_class, 600, 600, "test");
	void *p1 = new(point, 30, 500, 30);
	void *p2 = new(point, 400, 400, 40);
	draw_line(mlx_ptr, p1, p2);
	while (1);
	return (0);
}