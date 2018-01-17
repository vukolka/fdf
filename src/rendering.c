#include <mlx.h>
#include <libft.h>
#include <Point.h>
#include "../fdf.h"

void	*create_new_image(void *mlx, t_scene_state *state)
{
	void	*to_fill;

	to_fill= mlx_new_image(mlx, state->width, state->height);
	return (to_fill);
}

void	*fill_image(void *image, t_list *scene)
{
	t_point *current;

	while (scene)
	{
		current = (t_point*)scene->content;
		scene = scene->next;
	}
}

void	*delete_image(void *image)
{

}

void	put_image(void	*image)
{

}

void render_scene(t_list *scene, void *mlx)
{
	static void	*image;

	image = create_new_image(mlx, state);
	fill_image(image, scene);
	put_image(image);
	delete_image(image);
	free(scene);
}