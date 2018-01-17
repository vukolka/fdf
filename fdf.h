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
#include <mlx.h>

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
}				t_scene_state;

void render_scene(t_list *scene, void *mlx);
t_list	*calculate_scene(t_scene_state *state, void **s_map);
void loop(t_scene_state *state, void **s_map, void *mlx);
void	apply_events(int keycode, t_scene_state *scene_state);
int		apply_transormation(void **s_map, int keycode);
void 	draw_line(void *s_mlx, void *v1, void *v2);
void	**parce_map(t_list **map, char *name);
void	for_each_lst(t_list *lst, void (*f)(void *, int , int , int), ...);
void	modify_vector(void *s_vector, int x, int y, int z);
void	move_right(void **map);
void	close_win();
void	apply_hooks(void **s_mlx, void **map);
int		render_screen(unsigned int keycode, void *param);
void	move_left(void **map);
void	draw_poligons(void *mlx, void *s_map);
int		*apply_rotation(void *s_vector, double rx, double ry, double rz);
void	put_point(void *s_mlx, int x, int y, int color);

#endif
