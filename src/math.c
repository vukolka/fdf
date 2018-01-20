#include <Point.h>
#include <stdlib.h>
#include <math.h>
#include <ft_printf.h>
#include <new.h>
#include "../fdf.h"

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

int 	*apply_state(void *s_vector, t_scene_state *state)
{
	t_point vector;
	t_point *self;

	self = (t_point *)s_vector;
	vector.x = self->x + state->x;
	vector.y = self->y + state->y;
	vector.z = self->z;
	vector.x *= state->scale;
	vector.y *= state->scale;
	vector.z *= state->scale / 4;
	return (apply_rotation(&vector, state->rot_x, state->rot_y, 0));
}