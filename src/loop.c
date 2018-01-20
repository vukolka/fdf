#include <new.h>
#include <Image.h>
#include "../fdf.h"

void loop(t_scene_state *state, void **s_map)
{
	void *img;

	img = new(g_image, state->width, state->height);
	draw_poligons(s_map, img);
}