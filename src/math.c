#include <Point.h>
#include <stdlib.h>
#include <math.h>

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
