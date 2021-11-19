#include "fdf.h"

static void	params_rotate(int keycode, t_mlx *mlx)
{
	if (keycode == Q)
		mlx->params->yaw += 5 * DEG_2_RAD;
	if (keycode == E)
		mlx->params->yaw -= 5 * DEG_2_RAD;
	if (keycode == UP)
		mlx->params->pitch -= 5 * DEG_2_RAD;
	if (keycode == DOWN)
		mlx->params->pitch += 5 * DEG_2_RAD;
	if (keycode == LEFT)
		mlx->params->roll -= 5 * DEG_2_RAD;
	if (keycode == RIGHT)
		mlx->params->roll += 5 * DEG_2_RAD;
}

static void	params_zoom(int keycode, t_mlx *mlx)
{
	if (keycode == LSHIFT)
		mlx->params->scale_factor += 5;
	if (keycode == LCTRL)
		mlx->params->scale_factor -= 5;
}

static void	params_translate(int keycode, t_mlx *mlx)
{
	if (keycode == W)
		mlx->params->trans_y += 5;
	if (keycode == S)
		mlx->params->trans_y -= 5;
	if (keycode == A)
		mlx->params->trans_x -= 5;
	if (keycode == D)
		mlx->params->trans_x += 5;
}

int	key_events(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		free_mlx(mlx);
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		params_translate(keycode, mlx);
	if (keycode == LSHIFT || keycode == LCTRL)
		params_zoom(keycode, mlx);
	if (keycode == Q || keycode == E || keycode == UP || keycode == DOWN)
		params_rotate(keycode, mlx);
	if (keycode == LEFT || keycode == RIGHT)
		params_rotate(keycode, mlx);
	if (keycode == TAB)
		mlx->params->projection = !mlx->params->projection;
	if (keycode == R)
		init_params(mlx);
	draw(mlx);
	return (0);
}
