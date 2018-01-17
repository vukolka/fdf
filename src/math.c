#include <Point.h>
#include <stdlib.h>
#include <math.h>
#include <ft_printf.h>
#include <new.h>
#include "../fdf.h"

t_list	*calculate_scene(t_scene_state *state, void **s_map)
{
	t_point ***map;
	t_list *scene;
	int i;
	int j;

	i = 0;
	j = 0;
	map = (t_point***)s_map;
	scene = NULL;
	while (map[i])
	{
		while (map[i][j])
		{
			ft_lstadd(&scene, ft_lstnew(apply_rotation(map[i][j],
			state->rot_x, state->rot_y, state->rot_z), sizeof(int) * 2);
			j++;
		}
		j = 0;
		i++;
	}
	return (scene);
};

int		*apply_rotation(void *s_vector, double rx, double ry, double rz)
{
	t_point *vector;
	int x;
	int y;
	int z;
	int *res;

	res = malloc(8);
	vector = s_vector;
	x = vector->x;
	y = vector->y;
	z = vector->z;
	y = (int) (y * cos(rx) + z * sin(rx));
	z = (int) (z * cos(rx) - y * sin(rx));
	x  = (int) (x * cos(ry) - z * sin(ry));
	x  = (int) (x * cos(rz) + y * sin(rz));
	y  = (int) (y * cos(rz) - x * sin(rz));
	res[0] = x;
	res[1] = y;
	return (res);
}
