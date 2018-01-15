#include <libft.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <new.h>
#include <Point.h>
#include <ft_printf.h>

void	***get_2d_array(t_list *map, int rows, int cols)
{
	t_point			***array;
	int				i;
	int				j;

	j = 0;
	i = 0;
	array = malloc((rows + 1) * sizeof(t_point ***));
	while (i < rows)
	{
		array[i] = malloc(sizeof(t_point**) * (cols + 1));
		while (j < cols)
		{
			array[i][j] = map->content;
			ft_printf("i = %d, j = %d, adr = %#lx\n",i, j, array[i][j]);
			j++;
			map = map->next;
		}
		array[i][j] = NULL;
		j = 0;
		i++;
	}
	array[i] = NULL;
	return ((void ***)array);
}

void	***parce_map(t_list **map, char *name)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	int		z;
	int 	cols;

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
				ft_lstadd(map, ft_lstnew(new(point, j * 30 + 50, i * 30 + 50, (ft_atoi(line + z)) * 12), sizeof(t_point)));
				while (ft_isdigit(line[z]))
					z++;
				j++;
			}
			else
				z++;
		}
		cols = j;
		z = 0;
		j = 0;
		i++;
		free(line);
	}
	close(fd);
	return (get_2d_array(*map, i, cols));
}
