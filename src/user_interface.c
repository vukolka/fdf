#include <new.h>
#include <Image.h>
#include <MLXConn.h>
#include "../fdf.h"

void put_user_interface(t_scene_state *state)
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
