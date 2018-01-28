/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:45:30 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 12:45:31 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# define MOVE_RIGHT 124
# define MOVE_LEFT 123
# define MOVE_UP 126
# define MOVE_DOWN 125
# define X_ROTATION 125
# define Y_ROTATION 125
# define Z_ROTATION 125
# define SCALE_PLUS 125
# define SCALE_MINUS 125
# define CLOSE_WIN 125
# define DIFF_LINES 1
# define EMPTY_LINES 2
# define NOT_A_NUMBER 3
# define BADFILEDIS 4
# include <stdarg.h>
# include <libft.h>
# include "mlx.h"

typedef struct	s_math_vars
{
	int			dx;
	int			dy;
	int			ii;
	int			err;
	int			y;
	int			i;
}				t_math_vars;

typedef struct	s_scene_map
{
	int			x;
	int			y;
}				t_scene_map;

typedef struct	s_scene_state
{
	double		rot_x;
	double		rot_y;
	double		rot_z;
	int			x;
	int			y;
	int			scale;
	int			width;
	int			height;
	int			offset;
}				t_scene_state;

void			put_user_interface(t_scene_state *state);
void			get_rows_cols(void *s_map, t_scene_state *state);
void			ft_print_error(int error);
void			*parce_map(char *name);
void			put_image(void *s_image, int x, int y);
void			loop(t_scene_state *state, void **s_map);
void			apply_events(int keycode,
				t_scene_state *scene_state, void *map);
int				apply_transormation(int keycode, void *param);
void			draw_line(t_scene_state *state,
				void *v2, void *v1, void *image);
int				*apply_state(void *vector, t_scene_state *state);
void			apply_hooks(void **s_mlx, void **map);
void			draw_poligons(void *s_map, void *image, t_scene_state *state);
int				*apply_rotation(void *s_vector,
				double rx, double ry, double rz);
void			put_point(int x, int y, int color, void *image);

#endif
