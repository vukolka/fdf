/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:50:11 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/27 12:50:12 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <new.h>
#include <image.h>
#include <mlxconn.h>
#include <ft_printf.h>
#include "../fdf.h"

void	loop(t_scene_state *state, void **s_map)
{
	void		*img;
	t_mlx_class *mlx;

	mlx = (t_mlx_class*)get_mlx(NULL);
	mlx_clear_window(mlx->conn, mlx->winx);
	img = new(g_image, state->width, state->height);
	draw_poligons(s_map, img, state);
	put_image(img, 0, 0);
	put_user_interface(state);
	delete(img);
}
