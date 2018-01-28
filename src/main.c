/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:54:12 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/27 12:54:13 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <point.h>
#include <string.h>
#include <classes_lib.h>
#include <mlxconn.h>
#include <fcntl.h>
#include <get_next_line.h>
#include "ft_printf.h"
#include "new.h"
#include "../fdf.h"
#include "../mlx.h"
#include <math.h>
#include <image.h>

int		main(int argc, char **argv)
{
	void	*map;
	void	*mlx;

	make_classes();
	mlx = new(g_mlx_class, 1280, 760, "fdf");
	get_mlx(mlx);
	map = parce_map(argv[1]);
	apply_hooks(&mlx, map);
	mlx_loop(((t_mlx_class*)mlx)->conn);
	return (0);
}
