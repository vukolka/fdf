#include <libft.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <new.h>
#include <Point.h>
#include <ft_printf.h>
#include <Linked_list.h>
#include "../fdf.h"

int		skip_digit_und_spaces(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]) && *line)
		i++;
	while (ft_isspace(line[i]) && *line)
		i++;
	return (i);
}

static void *get_2d_map(void *list, int rows, int cols)
{
	t_point	***map;
	int		y;
	int 	x;

	x = 0;
	y = 0;
	map = malloc(rows * sizeof(t_point**));
	if (!map)
		return (NULL);
	while (x < rows)
	{
		map[x] = malloc((cols + 1) * sizeof(t_point*));
		while (y < cols)
		{
			map[x][y] = ((t_llist*)list)->content;
			list = ((t_llist*)list)->next;
			y++;
		}
		map[x][y] = 0;
		y = 0;
		x++;
	}
	map[rows] = 0;
	return ((void *)map);
}

static void	*get_map(int fd, int cols, int rows)
{
	char	*line;
	int		i;
	int		j;
	int		z;
	void	*temp_map;

	z = 0;
	j = 0;
	i = 0;
	temp_map = NULL;
	while (get_next_line(fd, &line))
	{
		while (line[j])
		{
			llst_add(&temp_map, new(g_list,
				new(point, z, i, ft_atoi(line + j))));
			j += skip_digit_und_spaces(line + j);
			z++;
		}
		if (i > 0)
			if (cols != z)
				ft_print_error(DIFF_LINES);
		cols = z;
		z = 0;
		j = 0;
		i++;
	}
	rows = i;
	return (get_2d_map(temp_map, rows, cols));
}

void		*parce_map(char *name)
{
	int		fd;
	void	*map;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_printf("error\n");
	map = get_map(fd, 0, 0);
	return (map);
}