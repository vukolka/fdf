#include <libft.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <new.h>
#include <Point.h>

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
				ft_lstadd(map, ft_lstnew(new(point, j * 20 + 50, i * 20 + 50, (ft_atoi(line + z)) * 2), sizeof(t_point)));
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