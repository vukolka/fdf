#include <new.h>
#include <Image.h>
#include <MLXConn.h>
#include "../fdf.h"

void loop(t_scene_state *state, void **s_map)
{
	void *img;
	t_mlx_class *mlx;

	mlx = (t_mlx_class*)get_mlx(NULL);
	mlx_clear_window(mlx->conn, mlx->winx);
	img = new(g_image, state->width, state->height);
	draw_poligons(s_map, img, state);
	delete(img);
}