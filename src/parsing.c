/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:00:07 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/27 13:00:08 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <new.h>
#include <point.h>
#include <ft_printf.h>
#include <linked_list.h>
#include "../fdf.h"

int			skip_digit_und_spaces(char *line)
{
	int	i;

	i = 0;
	if (*line == '-')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
	{
		i++;
		while (ft_isalnum(line[i]))
			i++;
	}
	while (ft_isspace(line[i]) && *line)
		i++;
	return (i);
}

static void	*get_2d_map(void *list, int rows, int cols)
{
	t_point	***map;
	int		y;
	int		x;

	x = 0;
	y = 0;
	map = malloc((rows + 1) * sizeof(t_point**));
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

static void	i_hate_doing_this(int *pint, int *pint1, int *pint2, void **pvoid)
{
	*pint = 0;
	*pint1 = 0;
	*pint2 = 0;
	*pvoid = NULL;
}

static void	*get_map(int fd, int cols, int rows)
{
	char	*line;
	int		i;
	int		j;
	int		z;
	void	*temp_map;

	i_hate_doing_this(&i, &j, &z, &temp_map);
	while (get_next_line(fd, &line))
	{
		while (line[j])
		{
			llst_add(&temp_map, new(g_list,
				new(g_point, z, i, ft_atoi(line + j))));
			j += skip_digit_und_spaces(line + j);
			z++;
		}
		if (i > 0 && cols != z)
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
		ft_print_error(BADFILEDIS);
	map = get_map(fd, 0, 0);
	return (map);
}
