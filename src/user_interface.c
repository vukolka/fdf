/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:01:27 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/27 13:01:28 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <new.h>
#include <image.h>
#include <mlxconn.h>
#include "../fdf.h"

void	put_user_interface(t_scene_state *state)
{
	t_mlx_class *mlx;

	mlx = get_mlx(NULL);
	mlx_string_put(mlx->conn, mlx->winx, 20, (state->height / 30),
				0xFFFFFF, "use arrows to transorm");
	mlx_string_put(mlx->conn, mlx->winx, 20, (state->height / 30 * 2),
				0xFFFFFF, "use numpad to rotate");
	mlx_string_put(mlx->conn, mlx->winx, 20, (state->height / 30 * 3),
				0xFFFFFF, "press num0 to translate to origin");
	mlx_string_put(mlx->conn, mlx->winx, 20, (state->height / 30 * 4),
				0xFFFFFF, "press esc to quite");
	mlx_string_put(mlx->conn, mlx->winx, 20, (state->height / 30 * 5),
				0xFFFFFF, "use + and - to scale");
}
