//
// Created by fenrir on 01/09/2020 02:04:17.
//

#include "../header/wolf.h"
#include "../header/key.h"

int		ft_press(int keycode, t_wolf *wolf)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		wolf->player.forward = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		wolf->player.backward = 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		wolf->player.turn_right = 1;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		wolf->player.turn_left = 1;
	else if (keycode == KEY_SHIFT_L || keycode == KEY_SHIFT_R)
		wolf->player.move_speed = 0.2;
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(wolf->win.my_mlx, wolf->win.win);
		ft_leave(wolf);
	}
	return (0);
}

int		ft_release(int key, t_wolf *wolf)
{
	if (key == KEY_W || key == KEY_UP)
		wolf->player.forward = 0;
	else if (key == KEY_S || key == KEY_DOWN)
		wolf->player.backward = 0;
	else if (key == KEY_D || key == KEY_RIGHT)
		wolf->player.turn_right = 0;
	else if (key == KEY_A || key == KEY_LEFT)
		wolf->player.turn_left = 0;
	else if (key == KEY_SHIFT_L || key == KEY_SHIFT_R)
		wolf->player.move_speed = 0.05;
	return (0);
}
