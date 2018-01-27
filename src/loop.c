#include <new.h>
#include <Image.h>
#include <MLXConn.h>
#include <ft_printf.h>
#include "../fdf.h"

void loop(t_scene_state *state, void **s_map)
{
	void		*img;
	t_mlx_class *mlx;

	//TODO Map always stays in the center of the window
	mlx = (t_mlx_class*)get_mlx(NULL);
	//TODO move mlx_clear_window to apply transformation
	mlx_clear_window(mlx->conn, mlx->winx);

	img = new(g_image, state->width, state->height);
	draw_poligons(s_map, img, state);
	put_image(img, 0, 0);

	put_user_interface(state);
	delete(img);
}