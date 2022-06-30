/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:15:08 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/29 22:43:09 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setting_up_hook(t_data mlx_data)
{
	mlx_loop_hook(mlx_data.mlx_ptr, &handle_no_event, &mlx_data);
	mlx_mouse_hook(mlx_data.win_ptr, &handle_mouse, &mlx_data);
	mlx_hook(mlx_data.win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		&mlx_data);
	mlx_hook(mlx_data.win_ptr, DestroyNotify, StructureNotifyMask,
		&handle_destroy, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
}

void	moving_the_view(int keysym, t_data *mlx_data)
{
	if (keysym == XK_w || keysym == XK_Up)
		mlx_data->boundary_y += mlx_data->intensity;
	else if (keysym == XK_s || keysym == XK_Down)
		mlx_data->boundary_y -= mlx_data->intensity;
	else if (keysym == XK_a || keysym == XK_Left)
		mlx_data->boundary_x -= mlx_data->intensity;
	else if (keysym == XK_d || keysym == XK_Right)
		mlx_data->boundary_x += mlx_data->intensity;
	exec_equation(*mlx_data);
}

void	hook_with_refresh(int keysym, t_data *mlx_data)
{
	if (keysym == XK_Page_Up)
		mlx_data->precision++;
	else if (keysym == XK_Page_Down)
		mlx_data->precision--;
	else if (keysym == XK_minus && mlx_data->color.color_select > 0)
		mlx_data->color.color_select--;
	else if (keysym == XK_equal && mlx_data->color.color_select < 6)
		mlx_data->color.color_select++;
	exec_equation(*mlx_data);
}

void	change_value_from_mouse_position(t_data *mlx_data)
{
	int		x;
	int		y;
	double	result_x;
	double	result_y;

	if (mlx_mouse_get_pos(mlx_data->mlx_ptr, mlx_data->win_ptr, &x, &y) == 0)
		return ;
	result_x = mlx_data->boundary_x + x / (WIN_SIZE / mlx_data->size);
	result_y = mlx_data->boundary_y - y / (WIN_SIZE / mlx_data->size);
	if (result_x != mlx_data->var_pos.x || result_y != mlx_data->var_pos.y)
	{
		mlx_data->var_pos.x = result_x;
		mlx_data->var_pos.y = result_y;
		exec_equation(*mlx_data);
	}
}
