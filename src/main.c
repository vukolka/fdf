#include <Point.h>
#include <String.h>
#include <classes_lib.h>
#include <MLXConn.h>
#include <mlx.h>
#include <fcntl.h>
#include <get_next_line.h>
#include "ft_printf.h"
#include "new.h"
#include <math.h>


void	parce_map(t_list **map, char *name)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		while (line[z])
		{
			if (ft_isdigit(line[z]))
			{
				ft_lstadd(map, ft_lstnew(new(point, j * 15 + 50, i * 15 + 50, (ft_atoi(line + z)) * 2), sizeof(t_point)));
				while (ft_isdigit(line[z]))
					z++;
				j++;
			}
			else
				z++;
		}
		z = 0;
		j = 0;
		i++;
		free(line);
	}
	close(fd);
}

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

void	put_point(void *s_vector, void *s_mlx)
{
	t_point *vector;
	t_mlx_class *mlx;
	int 	*res;

	mlx = s_mlx;
	vector = s_vector;
	res = apply_rotation(s_vector, 0.6, 0.5, 0.2);
	mlx_pixel_put(mlx->conn, mlx->winx, res[0], res[1], 255);
	free(res);
}

void	put_map(t_list *map, void *mlx)
{
	while (map)
	{
		put_point(map->content, mlx);
		map = map->next;
	}
}

int     main(int argc, char **argv)
{
	t_list	*map;
	void	*mlx;

	map = NULL;
	make_classes();
	mlx = new(g_mlx_class, 600, 400, "This is how you get fucked");
	parce_map(&map, argv[1]);
	put_map(map, mlx);
	mlx_loop(((t_mlx_class*)mlx)->conn);
	return (0);
}