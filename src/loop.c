#include "../fdf.h"

void loop(t_scene_state *state, void **s_map, void *mlx)
{
	t_list	*scene;

	scene = calculate_scene(state, s_map);
	render_scene(scene, mlx);
}