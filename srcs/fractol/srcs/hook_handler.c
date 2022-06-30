/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:10:58 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/29 23:04:32 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(void *data)
{
	t_data	*mlx_data;

	mlx_data = (t_data *) data;
	if (mlx_data->var_pos.boolean == 1 && (mlx_data->funct == &julia_set
			|| mlx_data->funct == &burning_julia_set))
		change_value_from_mouse_position(mlx_data);
	return (0);
}

/*
* Note à moi-même parce que j'ai bien galeré ahah, pour le zoom je modifie
* le "boundary", c'est à dire la borne du repaire (graphique en sommes).
* Par exemple, pour mandelbrot le graph est de x:-2 à x:2 et y:-2 à y:2
* Si je zoom sur le point A (situé en x:1 et y:1), je reduis les bornes
* par rapport à la puissance du zoom.
* Ce qui fait pour mon exemple du point A et d'un zoom x2
* x:-1.5 à 0.5 et y:-1.5 à 0.5, du coup tout le repaire s'est agrandi et décalé.
* Et du coup le point A (celui où on a zoomé ^^) est reste sur la meme position
* par rapport à l'écran.
*/
int	handle_mouse(int button, int x, int y, t_data *mlx_data)
{
	if (button == 4)
	{
		mlx_data->size -= mlx_data->intensity;
		mlx_data->boundary_x -= (mlx_data->boundary_x - (mlx_data->boundary_x
					+ x / (WIN_SIZE / mlx_data->intensity)));
		mlx_data->boundary_y -= (mlx_data->boundary_y - (mlx_data->boundary_y
					- y / (WIN_SIZE / mlx_data->intensity)));
		exec_equation(*mlx_data);
	}
	else if (button == 5)
	{
		mlx_data->size += mlx_data->intensity;
		mlx_data->boundary_x -= mlx_data->intensity / 2;
		mlx_data->boundary_y -= mlx_data->intensity / -2;
		exec_equation(*mlx_data);
	}
	return (0);
}

int	handle_destroy(t_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img.mlx_img);
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
	exit (0);
}

int	handle_keypress(int keysym, t_data *mlx_data)
{
	if (keysym == XK_Escape)
	{
		mlx_data->var_pos.boolean = 0;
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img.mlx_img);
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	}
	else if (keysym == XK_w || keysym == XK_Up || keysym == XK_s
		|| keysym == XK_Down || keysym == XK_a || keysym == XK_Left
		|| keysym == XK_d || keysym == XK_Right)
		moving_the_view(keysym, mlx_data);
	else if (keysym == XK_space)
		mlx_data->var_pos.boolean = 1 - mlx_data->var_pos.boolean;
	else if (keysym == XK_Page_Up || keysym == XK_Page_Down
		|| keysym == XK_minus || keysym == XK_equal)
		hook_with_refresh(keysym, mlx_data);
	else if (keysym == XK_Home)
		mlx_data->intensity = mlx_data->intensity / 10;
	else if (keysym == XK_End)
		mlx_data->intensity = mlx_data->intensity * 10;
	return (0);
}
