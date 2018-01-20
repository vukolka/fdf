#ifndef FDF_FDF_H
#define FDF_FDF_H
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


#include <stdarg.h>
#include <libft.h>
#include "mlx.h"


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
	int 		x;
	int 		y;
	int 		scale;
	int 		width;
	int 		height;
	int			offset;
}				t_scene_state;

void 	loop(t_scene_state *state, void **s_map);
void	apply_events(int keycode, t_scene_state *scene_state);
int		apply_transormation(int keycode, void *param);
void	draw_line(t_scene_state *state, void *v2, void *v1, void *image);
void	**parce_map(t_list **map, char *name);
int 	*apply_state(void *vector, t_scene_state *state);
void ** parce_map(t_list **map, char *name);
void	apply_hooks(void **s_mlx, void **map);
void	draw_poligons(void *s_map, void *image, t_scene_state *state);
int		*apply_rotation(void *s_vector, double rx, double ry, double rz);
void	put_point(int x, int y, int color, void *image);

#endif
